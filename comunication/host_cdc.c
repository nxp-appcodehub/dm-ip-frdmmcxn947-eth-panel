/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016, 2018-2019, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <usb_comunication.h>
#include "usb_host_config.h"
#include "usb_host.h"
#include "usb_host_cdc.h"
#include "host_cdc.h"
#include "fsl_debug_console.h"
#include "fsl_component_serial_manager.h"
#include "board.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Variables
 ******************************************************************************/

static uint8_t g_attached = false;

USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
uint8_t s_DataBuffer[USB_HOST_CDC_BUFFER_NUM * 2][USB_DATA_ALIGN_SIZE_MULTIPLE(USB_HOST_SEND_RECV_PER_TIME)];
usb_uart_buffer_struct_t g_EmptyBuffer[USB_HOST_CDC_BUFFER_NUM];
usb_uart_buffer_struct_t g_EmptySendBuffer[USB_HOST_CDC_BUFFER_NUM];

usb_uart_buffer_struct_t *g_EmptyQueue;
usb_uart_buffer_struct_t *g_EmptySendQueue;

usb_uart_buffer_struct_t *g_CurrentUartRecvNode;

usb_uart_buffer_struct_t *g_UsbSendQueue;
usb_uart_buffer_struct_t *g_UsbSendNode;
usb_uart_buffer_struct_t *g_CurrentUsbRecvNode;

usb_uart_buffer_struct_t *g_UartSendQueue;
usb_uart_buffer_struct_t *g_UartSendNode;

volatile uint8_t g_UsbSendBusy;

volatile uint8_t g_UartSendBusy;

usb_device_handle cdcDeviceHandle;
/*the data interface handle , this handle is init in the class init function*/
usb_host_class_handle cdcDataInterfaceHandle;
/*the control  interface handle , this handle is init in the class init function*/
usb_host_class_handle cdcControlIntfHandle;

USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE) usb_host_cdc_line_coding_struct_t g_LineCode;

char usbRecvUart[USB_HOST_CDC_UART_RX_MAX_LEN];

extern uint8_t g_AttachFlag;
extern serial_write_handle_t g_UartTxHandle;
extern serial_write_handle_t g_UartRxHandle;

uint32_t g_UartActive;
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief host cdc enter critical function.
 *
 */
void USB_HostCdcEnterCritical(uint8_t *sr)
{
#if defined(__GIC_PRIO_BITS)
    if ((__get_CPSR() & CPSR_M_Msk) == 0x13)
#else
    if (__get_IPSR())
#endif
    {
        *sr = portSET_INTERRUPT_MASK_FROM_ISR();
    }
    else
    {
        portENTER_CRITICAL();
    }
}
/*!
 * @brief host cdc exit critical function.
 *
 */
void USB_HostCdcExitCritical(uint8_t sr)
{
#if defined(__GIC_PRIO_BITS)
    if ((__get_CPSR() & CPSR_M_Msk) == 0x13)
#else
    if (__get_IPSR())
#endif
    {
        portCLEAR_INTERRUPT_MASK_FROM_ISR(sr);
    }
    else
    {
        portEXIT_CRITICAL();
    }
}

/*!
 * @brief USB_HostCdcInitBuffer function.
 *
 * Both send buffer and receive buffer are queue buffer, the data from the uart will be stored in send queue
 * the data from the usb device cdc will be stored in uart send queue . all the data will be stored by order, so as to
 * the data is output to the uart by its original sequence.
 *
 */
void USB_HostCdcInitBuffer(void)
{
    uint8_t usbOsaCurrentSr = 0U; 
    uint8_t index;

    USB_HostCdcEnterCritical(&usbOsaCurrentSr);
    for (index = 0; index < USB_HOST_CDC_BUFFER_NUM; ++index)
    {
        g_EmptyBuffer[index].buffer = &s_DataBuffer[index][0];
    }
    for (index = 0; index < USB_HOST_CDC_BUFFER_NUM; ++index)
    {
        g_EmptySendBuffer[index].buffer = &s_DataBuffer[USB_HOST_CDC_BUFFER_NUM + index][0];
    }

    g_EmptyQueue = &g_EmptyBuffer[0];
    usb_uart_buffer_struct_t *p;
    p = g_EmptyQueue;
    for (int m = 1; m < (sizeof(g_EmptyBuffer) / sizeof(usb_uart_buffer_struct_t)); m++)
    {
        p->next       = &g_EmptyBuffer[m];
        p->dataLength = 0;
        p             = p->next;
    }
    p->next               = NULL;
    g_CurrentUartRecvNode = g_EmptyQueue;
    g_EmptyQueue          = g_EmptyQueue->next;

    g_EmptySendQueue = &g_EmptySendBuffer[0];
    p                = g_EmptySendQueue;
    for (int m = 1; m < (sizeof(g_EmptySendBuffer) / sizeof(usb_uart_buffer_struct_t)); m++)
    {
        p->next       = &g_EmptySendBuffer[m];
        p->dataLength = 0;
        p             = p->next;
    }
    p->next = NULL;
    USB_HostCdcExitCritical(usbOsaCurrentSr);

    g_UsbSendQueue  = NULL;
    g_UartSendQueue = NULL;
    g_UsbSendBusy   = 0;
    g_UartSendBusy  = 0;
    g_UartActive    = 0;
}

/*!
 * @brief host cdc interrupt transfer callback.
 *
 * This function is used as callback function for interrupt transfer . Interrupt transfer is used to implement
 * asynchronous notification of UART status as pstn sepc. This callback suppose the device will return SerialState
 * notification. If there is need to suppose other notification ,please refer pstn spec 6.5 and cdc spec6.3.
 * @param param    the host cdc instance pointer.
 * @param data     data buffer pointer.
 * @param dataLength data length.
 * @status         transfer result status.
 */
void USB_HostCdcInterruptCallback(void *param, uint8_t *data, uint32_t dataLength, usb_status_t status)
{
    usb_host_cdc_acm_state_struct_t *state = (usb_host_cdc_acm_state_struct_t *)data;

    if (status != kStatus_USB_Success)
    {
        if (status == kStatus_USB_TransferCancel)
        {
            usb_echo("cdc transfer cancel\r\n");
        }
        else
        {
            usb_echo("cdc control transfer error\r\n");
        }
    }
    else
    { /*more information about SerialState ,please pstn spec 6.5.4 */
        usb_echo("get serial state value = %d\r\n", state->bmstate);
    }
}
/*!
 * @brief host cdc control transfer callback.
 *
 * This function is used as callback function for control transfer .
 *
 * @param param    the host cdc instance pointer.
 * @param data     data buffer pointer.
 * @param dataLength data length.
 * @status         transfer result status.
 */
void USB_HostCdcControlCallback(void *param, uint8_t *data, uint32_t dataLength, usb_status_t status)
{
    cdc_instance_struct_t *cdcInstance = (cdc_instance_struct_t *)param;

    if (status != kStatus_USB_Success)
    {
        usb_echo("data transfer error = %d , status \r\n");
        return;
    }

    if (cdcInstance->runWaitState == kUSB_HostCdcRunWaitSetControlInterface)
    {
        cdcInstance->runState = kUSB_HostCdcRunSetControlInterfaceDone;
    }
    else if (cdcInstance->runWaitState == kUSB_HostCdcRunWaitSetDataInterface)
    {
        cdcInstance->runState = kUSB_HostCdcRunSetDataInterfaceDone;
    }
    else if (cdcInstance->runWaitState == kUSB_HostCdcRunWaitGetLineCode)
    {
        cdcInstance->runState = kUSB_HostCdcRunGetLineCodeDone;
    }
#if USB_HOST_UART_SUPPORT_HW_FLOW
    else if (cdcInstance->runWaitState == kUSB_HostCdcRunWaitSetCtrlState)
    {
        cdcInstance->runState = kUSB_HostCdcRunSetCtrlStateDone;
    }
#endif
    else if (cdcInstance->runWaitState == kUSB_HostCdcRunWaitGetState)
    {
        cdcInstance->runState = kUSB_HostCdcRunGetStateDone;
    }
    else
    {
    }
}


uint8_t USB_HostCdcAttached(void)
{
	return g_attached;
}

/*!
 * @brief host cdc task function.
 *
 * This function implements the host cdc action, it is used to create task.
 *
 * @param param   the host cdc instance pointer.
 */
void USB_HostCdcTask(void *param)
{
    usb_status_t status                = kStatus_USB_Success;
    cdc_instance_struct_t *cdcInstance = (cdc_instance_struct_t *)param;
    /* device state changes */
    if (cdcInstance->deviceState != cdcInstance->previousState)
    {
        cdcInstance->previousState = cdcInstance->deviceState;
        switch (cdcInstance->deviceState)
        {
            case kStatus_DEV_Idle:
                break;
            case kStatus_DEV_Attached:
                cdcInstance->runState = kUSB_HostCdcRunSetControlInterface;
                status                = USB_HostCdcInit(cdcInstance->deviceHandle, &cdcInstance->classHandle);
                usb_echo("cdc device attached\r\n");
                g_attached = false;
                break;
            case kStatus_DEV_Detached:
                cdcInstance->deviceState = kStatus_DEV_Idle;
                cdcInstance->runState    = kUSB_HostCdcRunIdle;
                USB_HostCdcDeinit(cdcInstance->deviceHandle, cdcInstance->classHandle);
                cdcInstance->dataInterfaceHandle    = NULL;
                cdcInstance->classHandle            = NULL;
                cdcInstance->controlInterfaceHandle = NULL;
                cdcInstance->deviceHandle           = NULL;
                usb_echo("cdc device detached\r\n");
                g_attached = false;
                break;
            default:
                break;
        }
    }

    /* run state */
    switch (cdcInstance->runState)
    {
        case kUSB_HostCdcRunIdle:
            if (g_AttachFlag)
            {
                	g_attached = true;
            }
            break;
        case kUSB_HostCdcRunSetControlInterface:
            cdcInstance->runWaitState = kUSB_HostCdcRunWaitSetControlInterface;
            cdcInstance->runState     = kUSB_HostCdcRunIdle;
            if (USB_HostCdcSetControlInterface(cdcInstance->classHandle, cdcInstance->controlInterfaceHandle, 0,
                                               USB_HostCdcControlCallback, &g_cdc) != kStatus_USB_Success)
            {
                usb_echo("set control interface error\r\n");
            }
            break;
        case kUSB_HostCdcRunSetControlInterfaceDone:
            cdcInstance->runWaitState = kUSB_HostCdcRunWaitSetDataInterface;
            cdcInstance->runState     = kUSB_HostCdcRunIdle;
            if (USB_HostCdcSetDataInterface(cdcInstance->classHandle, cdcInstance->dataInterfaceHandle, 0,
                                            USB_HostCdcControlCallback, &g_cdc) != kStatus_USB_Success)
            {
                usb_echo("set data interface error\r\n");
            }
            cdcInstance->bulkInMaxPacketSize =
                USB_HostCdcGetPacketsize(cdcInstance->classHandle, USB_ENDPOINT_BULK, USB_IN);
            break;
        case kUSB_HostCdcRunSetDataInterfaceDone:
            g_AttachFlag          = 1;
            cdcInstance->runState = kUSB_HostCdcRunGetStateDone;
            /*get the class-specific descriptor */
            /*usb_host_cdc_head_function_desc_struct_t *headDesc = NULL;
            usb_host_cdc_call_manage_desc_struct_t *callManage = NULL;
            usb_host_cdc_abstract_control_desc_struct_t *abstractControl = NULL;
            usb_host_cdc_union_interface_desc_struct_t *unionInterface =NULL;
            USB_HostCdcGetAcmDescriptor(cdcInstance->classHandle, &headDesc, &callManage, &abstractControl,
                                        &unionInterface);*/
            if (USB_HostCdcInterruptRecv(cdcInstance->classHandle, (uint8_t *)&cdcInstance->state,
                                         sizeof(cdcInstance->state), USB_HostCdcInterruptCallback,
                                         &g_cdc) != kStatus_USB_Success)
            {
                usb_echo("Error in USB_HostCdcInterruptRecv: %x\r\n", status);
            }
            break;
        case kUSB_HostCdcRunGetStateDone:
            cdcInstance->runWaitState = kUSB_HostCdcRunWaitSetCtrlState;
            cdcInstance->runState     = kUSB_HostCdcRunIdle;
#if USB_HOST_UART_SUPPORT_HW_FLOW
            USB_HostCdcSetAcmCtrlState(cdcInstance->classHandle, 1, 1, USB_HostCdcControlCallback, (void *)cdcInstance);
#else
            cdcInstance->runState = kUSB_HostCdcRunSetCtrlStateDone;
#endif
            break;
        case kUSB_HostCdcRunSetCtrlStateDone:
            cdcInstance->runWaitState = kUSB_HostCdcRunWaitGetLineCode;
            cdcInstance->runState     = kUSB_HostCdcRunIdle;
            USB_HostCdcGetAcmLineCoding(cdcInstance->classHandle, &g_LineCode, USB_HostCdcControlCallback,
                                        (void *)cdcInstance);
            break;
        case kUSB_HostCdcRunGetLineCodeDone:
            cdcInstance->runState = kUSB_HostCdcRunIdle;
            break;
        default:
            break;
    }
}

usb_status_t USB_HostCdcEvent(usb_device_handle deviceHandle,
                              usb_host_configuration_handle configurationHandle,
                              uint32_t event_code)
{
    usb_status_t status;
    uint8_t id;
    usb_host_configuration_t *configuration;
    uint8_t interface_index;
    usb_host_interface_t *hostInterface;
    uint32_t info_value = 0U;

    status = kStatus_USB_Success;

    switch (event_code)
    {
        case kUSB_HostEventAttach:
            /* judge whether is configurationHandle supported */
            configuration          = (usb_host_configuration_t *)configurationHandle;
            cdcDataInterfaceHandle = NULL;
            cdcDeviceHandle        = NULL;
            cdcControlIntfHandle   = NULL;

            for (interface_index = 0; interface_index < configuration->interfaceCount; ++interface_index)
            {
                hostInterface = &configuration->interfaceList[interface_index];
                id            = hostInterface->interfaceDesc->bInterfaceClass;

                if (id != USB_HOST_CDC_COMMUNICATIONS_CLASS_CODE)
                {
                    continue;
                }
                id = hostInterface->interfaceDesc->bInterfaceSubClass;
                if (id != USB_HOST_CDC_SUBCLASS_ACM_CODE)
                {
                    continue;
                }
                /*judge the subclass code */
                /*            id = hostInterface->interfaceDesc->bInterfaceProtocol;
                            if (id != USB_HOST_CDC_PROTOCOL_CODE)
                            {
                                continue;
                            }*/
                else
                {
                    cdcControlIntfHandle = hostInterface;
                    cdcDeviceHandle      = deviceHandle;
                }
            }
            for (interface_index = 0; interface_index < configuration->interfaceCount; ++interface_index)
            {
                hostInterface = &configuration->interfaceList[interface_index];
                id            = hostInterface->interfaceDesc->bInterfaceClass;

                if (id != USB_HOST_CDC_DATA_CLASS_CODE)
                {
                    continue;
                }
                id = hostInterface->interfaceDesc->bInterfaceSubClass;
                if (id != USB_HOST_CDC_DATA_SUBCLASS_CODE)
                {
                    continue;
                }
                id = hostInterface->interfaceDesc->bInterfaceProtocol;
                if (id != USB_HOST_CDC_DATA_PROTOCOL_CODE)
                {
                    continue;
                }
                else
                {
                    cdcDataInterfaceHandle = hostInterface;
                }
            }
            if ((NULL != cdcDataInterfaceHandle) && (NULL != cdcControlIntfHandle) && (NULL != cdcDeviceHandle))
            {
                status = kStatus_USB_Success;
            }
            else
            {
                status = kStatus_USB_NotSupported;
            }
            break;

        case kUSB_HostEventNotSupported:
            break;

        case kUSB_HostEventEnumerationDone:
            if (g_cdc.deviceState == kStatus_DEV_Idle)
            {
                if ((cdcDeviceHandle != NULL) && (cdcDataInterfaceHandle != NULL) && (cdcControlIntfHandle != NULL))
                {
                    g_cdc.deviceState            = kStatus_DEV_Attached;
                    g_cdc.deviceHandle           = cdcDeviceHandle;
                    g_cdc.dataInterfaceHandle    = cdcDataInterfaceHandle;
                    g_cdc.controlInterfaceHandle = cdcControlIntfHandle;

                    USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDevicePID, &info_value);
                    usb_echo("device cdc attached:\r\npid=0x%x", info_value);
                    USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDeviceVID, &info_value);
                    usb_echo("vid=0x%x ", info_value);
                    USB_HostHelperGetPeripheralInformation(deviceHandle, kUSB_HostGetDeviceAddress, &info_value);
                    usb_echo("address=%d\r\n", info_value);
                }
            }
            else
            {
                usb_echo("not idle cdc instance\r\n");
            }
            break;

        case kUSB_HostEventDetach:
            if (g_cdc.deviceState != kStatus_DEV_Idle)
            {
                g_cdc.deviceState = kStatus_DEV_Detached;
                g_AttachFlag      = 0;
            }
            break;

        default:
            break;
    }
    return status;
}
