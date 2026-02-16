#include "fsl_clock.h"

uint32_t LPI2C2_GetFreq(void)
{
    /* attach FRO 12M to FLEXCOMM2 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);

    return CLOCK_GetLPFlexCommClkFreq(2U);
}

uint32_t LPI2C3_GetFreq(void)
{
    /* attach FRO 12M to FLEXCOMM2 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom3Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM3);

    return CLOCK_GetLPFlexCommClkFreq(3U);
}

