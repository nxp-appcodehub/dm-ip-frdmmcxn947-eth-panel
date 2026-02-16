
# Copyright 2025 NXP
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.22.0)

include(${SdkRootDirPath}/cmake/extension/mcux.cmake)

project(dm-ip-frdmmcxn947-eth-panel LANGUAGES C CXX ASM)

include(${SdkRootDirPath}/CMakeLists.txt)

# Common ------------------
mcux_add_include(
    INCLUDES src
             board
             comunication
             measures
             measures/mikroe_accel4click
             measures/brd_temp_sensor
             linker
)

mcux_add_source(
    SOURCES src/FreeRTOSConfig_frag.h
            src/lwipopts.h
            src/main.c
            board/board.h
            board/board.c
            board/clock_config.h
            board/clock_config.c
            board/pin_mux.h
            board/pin_mux.c
            board/RTE_Device.h
            board/frdmmcxn947.c
            comunication/can_comunication.h
            comunication/can_comunication.c
            comunication/usb_comunication.h
            comunication/usb_comunication.c
            comunication/eth_comunication.h
            comunication/eth_comunication.c
            comunication/comunication.h
            comunication/comunication.c
            comunication/host_cdc.h
            comunication/host_cdc.c
            comunication/usb_host_config.h
            measures/measures.h
            measures/measures.c
            measures/mikroe_accel4click/mikroe_accel_4_click.h
            measures/mikroe_accel4click/mikroe_accel_4_click.c
            measures/brd_temp_sensor/brd_temp_sensor.h
            measures/brd_temp_sensor/brd_temp_sensor.c
)
# -------------------------

# Motor Control -----------
mcux_add_include(
    INCLUDES motor_control
)
mcux_add_source(
    SOURCES motor_control/mc_periph_init.h
            motor_control/mc_periph_init.c
            motor_control/motor_control.h
            motor_control/motor_control.c
            motor_control/m1_pmsm_appconfig.h
)
mcux_add_macro(
    CC "-DMC_EXAMPLE"
)
# -------------------------

# USB ---------------------
# -------------------------

# USB ---------------------
# -------------------------

# SDIO --------------------
# -------------------------

# ADC ---------------------
# -------------------------

# LWIP --------------------
mcux_add_macro(
    CC "-DUSE_RTOS=1\
        -DPRINTF_ADVANCED_ENABLE=1"
)
# -------------------------

# LVGL --------------------
mcux_add_include(
    INCLUDES gui_guider/custom
             gui_guider/generated
             gui_guider/generated/guider_customer_fonts
             gui_guider/generated/guider_fonts
             gui_guider/generated/images
             screen
)

mcux_add_source(
    SOURCES gui_guider/custom/lv_conf_ext.h
            gui_guider/custom/custom.h
            gui_guider/custom/custom.c
            gui_guider/generated/events_init.h
            gui_guider/generated/events_init.c
            gui_guider/generated/gui_guider.h
            gui_guider/generated/gui_guider.c
            gui_guider/generated/widgets_init.h
            gui_guider/generated/widgets_init.c
            gui_guider/generated/setup_scr_accelerometer_measure_screen.c
            gui_guider/generated/setup_scr_connection_config_screen.c
            gui_guider/generated/setup_scr_control_panel_screen.c
            gui_guider/generated/setup_scr_cpu_performance_screen.c
            gui_guider/generated/setup_scr_init_screen.c
            gui_guider/generated/setup_scr_menu_screen.c
            gui_guider/generated/setup_scr_server_ip_screen.c
            gui_guider/generated/setup_scr_set_time_screen.c
            gui_guider/generated/setup_scr_stand_by_screen.c
            gui_guider/generated/setup_scr_temperature_measure_screen.c
            gui_guider/generated/setup_scr_touch_measure_screen.c
            gui_guider/generated/guider_customer_fonts/*.h
            gui_guider/generated/guider_customer_fonts/*.c
            gui_guider/generated/guider_fonts/*.h
            gui_guider/generated/guider_fonts/*.c
            gui_guider/generated/images/*.h
            gui_guider/generated/images/*.c
            screen/lvgl_demo_utils.h
            screen/lvgl_demo_utils.c
            screen/lvgl_freertos.h
            screen/lvgl_freertos.c
            screen/screen_app.h
            screen/screen_app.c
            screen/screen.h
            screen/screen.c
)
# -------------------------

# Linker ------------------
mcux_remove_armgcc_linker_script(
    TARGETS debug release
    BASE_PATH ${SdkRootDirPath}
    LINKER ${device_root}/${soc_portfolio}/${soc_series}/${device}/gcc/MCXN947_cm33_core0_flash.ld
    STARTUP ${device_root}/${soc_portfolio}/${soc_series}/${device}/gcc/startup_MCXN947_cm33_core0.S
)
mcux_add_armgcc_linker_script(
    TARGETS debug release
    LINKER linker/MCXN947_cm33_core0_flash.ld
    STARTUP linker/startup_MCXN947_cm33_core0.S
)
# -------------------------

include(${SdkRootDirPath}/${board_root}/${board}/demo_apps/mc_pmsm/pmsm_enc/${multicore_foldername}/reconfig.cmake OPTIONAL)

mcux_convert_binary(BINARY ${APPLICATION_BINARY_DIR}/${MCUX_SDK_PROJECT_NAME}.bin)

