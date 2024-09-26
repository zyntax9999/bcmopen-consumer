/*
    Copyright 2000-2018 Broadcom Corporation

    <:label-BRCM:2011:DUAL/GPL:standard
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation (the "GPL").
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    
    A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
    writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
    
    :>
*/

#include "bp_defs.h"
#include "boardparms.h"



bp_pinmux_fn_defs_t g_pinmux_fn_defs[] = {
  { BP_PINMUX_FNTYPE_xMII | 0, BP_PINMUX_VAL_DUMMY },
  { BP_PINMUX_FNTYPE_xMII | 3, BP_PINMUX_VAL_DUMMY },
  { BP_PINMUX_FNTYPE_xMII | 4, BP_PINMUX_VAL_DUMMY },
  { BP_PINMUX_FNTYPE_xMII | 9, BP_PINMUX_VAL_DUMMY },
  { BP_PINMUX_FNTYPE_xMII | 12, 64 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 65 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 66 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 67 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 68 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 69 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 70 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 71 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 72 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 73 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 74 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 75 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 76 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 77 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 78 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 12, 79 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 80 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 81 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 82 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 83 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 84 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 85 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 86 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 87 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 88 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 89 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 90 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 11, 91 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 92 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 93 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 94 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 95 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 96 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 97 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 98 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 99 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 100 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 101 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 102 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_xMII | 13, 103 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_HS_SPI, 108 | BP_PINMUX_VAL_0 },
  { BP_PINMUX_FNTYPE_HS_SPI, 109 | BP_PINMUX_VAL_0 },
  { BP_PINMUX_FNTYPE_HS_SPI, 110 | BP_PINMUX_VAL_0 },
  { BP_PINMUX_FNTYPE_HS_SPI, 111 | BP_PINMUX_VAL_0 },
  { BP_PINMUX_FNTYPE_HS_SPI, 112 | BP_PINMUX_VAL_0 },
  { BP_PINMUX_FNTYPE_I2S, 14 | BP_PINMUX_VAL_2 },
  { BP_PINMUX_FNTYPE_I2S, 28 | BP_PINMUX_VAL_2 },
  { BP_PINMUX_FNTYPE_I2S, 29 | BP_PINMUX_VAL_2 },
  { BP_PINMUX_FNTYPE_I2S, 30 | BP_PINMUX_VAL_2 },
  { BP_PINMUX_FNTYPE_I2S, 31 | BP_PINMUX_VAL_2 },
  { BP_PINMUX_FNTYPE_PCM, 42 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_PCM, 43 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_PCM, 44 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_PCM, 45 | BP_PINMUX_VAL_1 },
  { BP_PINMUX_FNTYPE_NAND, 47 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 48 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 49 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 50 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 51 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 52 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 53 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 54 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 55 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 56 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 57 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 58 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 59 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 60 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_NAND, 61 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_EMMC, 62 | BP_PINMUX_VAL_3 },
  { BP_PINMUX_FNTYPE_EMMC, 63 | BP_PINMUX_VAL_3 },
};


bp_pinmux_defs_t g_pinmux_defs_0[] = {
  { bp_usNetLed0, 0, 0, 0 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 0, 1, 1 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 0, 20, 20 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 1, 2, 2 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 1, 3, 3 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 1, 21, 21 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 2, 4, 4 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 2, 5, 5 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 2, 22, 22 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 3, 6, 6 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 3, 7, 7 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 3, 23, 23 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 4, 8, 8 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 4, 9, 9 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 4, 24, 24 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 4, 10, 10 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 4, 11, 11 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed2, 4, 12, 12 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 4, 25, 25 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 6, 8, 8 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 6, 9, 9 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 6, 24, 24 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 6, 10, 10 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 6, 11, 11 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed2, 6, 12, 12 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 6, 25, 25 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, SF2_WAN_PORT_NUM, 8, 8 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, SF2_WAN_PORT_NUM, 9, 9 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, SF2_WAN_PORT_NUM, 24, 24 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, SF2_WAN_PORT_NUM, 10, 10 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, SF2_WAN_PORT_NUM, 11, 11 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed2, SF2_WAN_PORT_NUM, 12, 12 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, SF2_WAN_PORT_NUM, 25, 25 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 1, 16, 16 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 1, 17, 17 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 1, 27, 27 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, 0, 13, 13 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, 0, 14, 14 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed2, 0, 15, 15 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, 0, 26, 26 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed0, SF2_WAN_PORT_NUM, 13, 13 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed1, SF2_WAN_PORT_NUM, 14, 14 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed2, SF2_WAN_PORT_NUM, 15, 15 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usNetLed3, SF2_WAN_PORT_NUM, 26, 26 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },

  { bp_usGpioLedAggregateAct, -1, 28, 28 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usGpioLedAggregateLnk, -1, 29, 29 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED },
  { bp_usGpioLedWanAct, 0, 30, 30 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED},
  { bp_usGpioLedWanAct, 1, 31, 31 | BP_PINMUX_VAL_4 | BP_PINMUX_HWLED},
  { bp_usGpioLedPwmReserved, -1, 18, 18 | BP_PINMUX_VAL_4 | BP_PINMUX_PWMLED },
  { bp_usGpioLedPwmReserved, -1, 19, 19 | BP_PINMUX_VAL_4 | BP_PINMUX_PWMLED },

  { bp_usSerialLedData, -1, 0, 0 | BP_PINMUX_VAL_1},
  { bp_usSerialLedClk, -1, 1, 1 | BP_PINMUX_VAL_1 },
  { bp_usSerialLedMask, -1, 2, 2 | BP_PINMUX_VAL_1 },
  { bp_usSerialLedData, -1, 29, 29 | BP_PINMUX_VAL_1 },
  { bp_usSerialLedClk, -1, 30, 30 | BP_PINMUX_VAL_1 },
  { bp_usSerialLedMask, -1, 31, 31 | BP_PINMUX_VAL_1 },

  { bp_usUartSdin, 0, 106, 106 | BP_PINMUX_VAL_1},
  { bp_usUartSdout, 0, 107, 107 | BP_PINMUX_VAL_1},
  { bp_usUartSdin, 1, 25, 25 | BP_PINMUX_VAL_2},
  { bp_usUartSdout, 1, 24, 24 | BP_PINMUX_VAL_2},
  { bp_usUartSdin, 1, 42, 42 | BP_PINMUX_VAL_4},
  { bp_usUartSdout, 1, 43, 43 | BP_PINMUX_VAL_4},
  { bp_usUartSdin, 2, 5, 5 | BP_PINMUX_VAL_1},
  { bp_usUartSdout, 2, 6, 6 | BP_PINMUX_VAL_1},
  { bp_usUartCts, 2, 3, 3 | BP_PINMUX_VAL_1},
  { bp_usUartRts, 2, 4, 4 | BP_PINMUX_VAL_1},
  { bp_usUartSdin, 2, 23, 23 | BP_PINMUX_VAL_2},
  { bp_usUartSdout, 2, 22, 22 | BP_PINMUX_VAL_2},
  { bp_usUartCts, 2, 20, 20 | BP_PINMUX_VAL_2},
  { bp_usUartRts, 2, 21, 21 | BP_PINMUX_VAL_2},
  { bp_usUartSdin, 3, 20, 20 | BP_PINMUX_VAL_3},
  { bp_usUartSdout, 3, 21, 21 | BP_PINMUX_VAL_3},
  { bp_usUartSdin, 3, 26, 26 | BP_PINMUX_VAL_3},
  { bp_usUartSdout, 3, 27, 27 | BP_PINMUX_VAL_3},

  { bp_ReservedDslCtl, -1, 32, 32 | BP_PINMUX_VAL_2 | BP_VDSLCTL_0 },
  { bp_ReservedDslCtl, -1, 33, 33 | BP_PINMUX_VAL_2 | BP_VDSLCTL_1 },
  { bp_ReservedDslCtl, -1, 34, 34 | BP_PINMUX_VAL_2 | BP_VDSLCTL_2 },
  { bp_ReservedDslCtl, -1, 35, 35 | BP_PINMUX_VAL_2 | BP_VDSLCTL_3 },
  { bp_ReservedDslCtl, -1, 36, 36 | BP_PINMUX_VAL_2 | BP_VDSLCTL_4 },
  { bp_ReservedDslCtl, -1, 37, 37 | BP_PINMUX_VAL_2 | BP_VDSLCTL_5 },

  { bp_usRogueOnuEn, -1, 34, 34 | BP_PINMUX_VAL_3},
  { bp_usRogueOnuEn, -1, 40, 40 | BP_PINMUX_VAL_2},

  { bp_usGpioI2cSda, 0, 11, 11 | BP_PINMUX_VAL_2 },
  { bp_usGpioI2cScl, 0, 12, 12 | BP_PINMUX_VAL_2 },
  { bp_usGpioI2cSda, 0, 24, 24 | BP_PINMUX_VAL_3 },
  { bp_usGpioI2cScl, 0, 25, 25 | BP_PINMUX_VAL_3 },
  { bp_usGpioI2cSda, 1, 15, 15 | BP_PINMUX_VAL_6 },
  { bp_usGpioI2cScl, 1, 16, 16 | BP_PINMUX_VAL_6 },
  { bp_usGpioI2cSda, 1, 26, 26 | BP_PINMUX_VAL_2 },
  { bp_usGpioI2cScl, 1, 27, 27 | BP_PINMUX_VAL_2 },

  { bp_usI2sRxSdata, -1, 14, 14 | BP_PINMUX_VAL_2 },
  { bp_usI2sMclk, -1, 28, 28 | BP_PINMUX_VAL_2 },
  { bp_usI2sLrck, -1, 29, 29 | BP_PINMUX_VAL_2 },
  { bp_usI2sSclk, -1, 30, 30 | BP_PINMUX_VAL_2 },
  { bp_usI2sSdata, -1, 31, 31 | BP_PINMUX_VAL_2 },

  { bp_usPcmSdin, -1, 42, 42 | BP_PINMUX_VAL_1},
  { bp_usPcmSdout, -1, 43, 43 | BP_PINMUX_VAL_1},
  { bp_usPcmClk, -1, 44, 44 | BP_PINMUX_VAL_1},
  { bp_usPcmFs, -1, 45, 45 | BP_PINMUX_VAL_1},

  { bp_usSpiSlaveSelectNum, 0, 111, 111 | BP_PINMUX_VAL_0},
  { bp_usSpiSlaveSelectNum, 1, 112, 112 | BP_PINMUX_VAL_0},
  { bp_usSpiSlaveSelectNum, 2, 10, 10 | BP_PINMUX_VAL_1},
  { bp_usSpiSlaveSelectNum, 2, 25, 25 | BP_PINMUX_VAL_1},
  { bp_usSpiSlaveSelectNum, 3, 9, 9 | BP_PINMUX_VAL_1},
  { bp_usSpiSlaveSelectNum, 3, 26, 26 | BP_PINMUX_VAL_1},
  { bp_usSpiSlaveSelectNum, 4, 8, 8 | BP_PINMUX_VAL_1},
  { bp_usSpiSlaveSelectNum, 4, 27, 27 | BP_PINMUX_VAL_1},
  { bp_usSpiSlaveSelectNum, 5, 7, 7 | BP_PINMUX_VAL_1},
  { bp_usSpiSlaveSelectNum, 5, 28, 28 | BP_PINMUX_VAL_1},

  { bp_usUsbPwrFlt0, -1, 123, 123 | BP_PINMUX_VAL_2 },
  { bp_usUsbPwrOn0, -1, 124, 124 | BP_PINMUX_VAL_2 },
  { bp_usUsbPwrFlt1, -1, 121, 121 | BP_PINMUX_VAL_2 },
  { bp_usUsbPwrOn1, -1, 122, 122 | BP_PINMUX_VAL_2 },
  { bp_usUsbPwrFlt0, -1, 121, 121 | BP_PINMUX_VAL_1 },
  { bp_usUsbPwrOn0, -1, 122, 122 | BP_PINMUX_VAL_1 },
  { bp_usUsbPwrFlt1, -1, 123, 123 | BP_PINMUX_VAL_1 },
  { bp_usUsbPwrOn1, -1, 124, 124 | BP_PINMUX_VAL_1 },



  { bp_usMiiMdc, -1, 104, 104 | BP_PINMUX_VAL_1},
  { bp_usMiiMdio, -1, 105, 105 | BP_PINMUX_VAL_1},

  { bp_usVregSync, -1, 19, 19 | BP_PINMUX_VAL_2 },

  { bp_usSfpSigDetect, -1, 19, 19 | BP_PINMUX_VAL_6 },
  { bp_usSfpSigDetect, -1, 35, 35 | BP_PINMUX_VAL_3 },
  { bp_usSfpSigDetect, 0, 10, 10 | BP_PINMUX_VAL_2 },
  { bp_usSfpSigDetect, 0, 37, 37 | BP_PINMUX_VAL_1 },
  { bp_usSfpSigDetect, -1, 21, 21 | BP_PINMUX_VAL_6 },

  { bp_usPmdMACEwakeEn,  0, 33, 33 | BP_PINMUX_VAL_3 },
  { bp_usPmdMACEwakeEn,  0, 39, 39 | BP_PINMUX_VAL_2 },
  { bp_usPmdMACEwakeEn,  0, 41, 41 | BP_PINMUX_VAL_3 },

  { bp_usTsync1pps, -1, 4, 4 | BP_PINMUX_VAL_2 },
  { bp_usTsync1pps, -1, 13, 13 | BP_PINMUX_VAL_1 },

  { bp_ReservedAnyLed, -1, 64, 64 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(0) },
  { bp_ReservedAnyLed, -1, 65, 65 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(1) },
  { bp_ReservedAnyLed, -1, 66, 66 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(2) },
  { bp_ReservedAnyLed, -1, 67, 67 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(3) },
  { bp_ReservedAnyLed, -1, 68, 68 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(4) },
  { bp_ReservedAnyLed, -1, 69, 69 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(5) },
  { bp_ReservedAnyLed, -1, 70, 70 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(6) },
  { bp_ReservedAnyLed, -1, 71, 71 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(7) },
  { bp_ReservedAnyLed, -1, 72, 72 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(8) },
  { bp_ReservedAnyLed, -1, 73, 73 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(9) },
  { bp_ReservedAnyLed, -1, 74, 74 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(10) },
  { bp_ReservedAnyLed, -1, 75, 75 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(11) },
  { bp_ReservedAnyLed, -1, 76, 76 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(12) },
  { bp_ReservedAnyLed, -1, 77, 77 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(13)},
  { bp_ReservedAnyLed, -1, 78, 78 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(14)},
  { bp_ReservedAnyLed, -1, 79, 79 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(15)},
  { bp_ReservedAnyLed, -1, 80, 80 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(16) },
  { bp_ReservedAnyLed, -1, 81, 81 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(17) },
  { bp_ReservedAnyLed, -1, 82, 82 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(18) },
  { bp_ReservedAnyLed, -1, 83, 83 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(19) },
  { bp_ReservedAnyLed, -1, 84, 84 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(20) },
  { bp_ReservedAnyLed, -1, 85, 85 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(21) },
  { bp_ReservedAnyLed, -1, 86, 86 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(22) },
  { bp_ReservedAnyLed, -1, 87, 87 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(23) },
  { bp_ReservedAnyLed, -1, 88, 88 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(24) },
  { bp_ReservedAnyLed, -1, 89, 89 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(25) },
  { bp_ReservedAnyLed, -1, 90, 90 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(26)},
  { bp_ReservedAnyLed, -1, 91, 91 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(27) },
  { bp_ReservedAnyLed, -1, 92, 92 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(28) },
  { bp_ReservedAnyLed, -1, 93, 93 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(29) },
  { bp_ReservedAnyLed, -1, 94, 94 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(30)},
  { bp_ReservedAnyLed, -1, 95, 95 | BP_PINMUX_VAL_6 |  BP_PINMUX_OPTLED_NUM(31)},
 
  { bp_ReservedAnyGpio, -1, -1, BP_PINMUX_VAL_5 },
  { bp_ReservedAnyLed, -1, -1, BP_PINMUX_VAL_4 },

  { bp_usNetLed0, 0, 64, 64 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(0) },
  { bp_usNetLed1, 0, 65, 65 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(1) },
  { bp_usNetLed3, 0, 84, 84 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(20) },
  { bp_usNetLed0, 1, 66, 66 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(2) },
  { bp_usNetLed1, 1, 67, 67 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(3) },
  { bp_usNetLed3, 1, 85, 85 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(21) },
  { bp_usNetLed0, 2, 68, 68 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(4) },
  { bp_usNetLed1, 2, 69, 69 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(5) },
  { bp_usNetLed3, 2, 86, 86 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(22) },
  { bp_usNetLed0, 3, 70, 70 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(6) },
  { bp_usNetLed1, 3, 71, 71 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(7) },
  { bp_usNetLed3, 3, 87, 87 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(23) },
  { bp_usNetLed0, 4, 72, 72 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(8) },
  { bp_usNetLed1, 4, 73, 73 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(9) },
  { bp_usNetLed3, 4, 88, 88 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(24) },
  { bp_usNetLed0, 4, 74, 74 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(10) },
  { bp_usNetLed1, 4, 75, 75 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(11) },
  { bp_usNetLed2, 4, 76, 76 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(12) },
  { bp_usNetLed3, 4, 89, 89 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(25) },
  { bp_usNetLed0, 6, 72, 72 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(8) },
  { bp_usNetLed1, 6, 73, 73 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(9) },
  { bp_usNetLed3, 6, 88, 88 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(24) },
  { bp_usNetLed0, 6, 74, 74 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(10) },
  { bp_usNetLed1, 6, 75, 75 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(11) },
  { bp_usNetLed2, 6, 76, 76 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(12) },
  { bp_usNetLed3, 6, 89, 89 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(25) },
  { bp_usNetLed0, SF2_WAN_PORT_NUM, 72, 72 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(8) },
  { bp_usNetLed1, SF2_WAN_PORT_NUM, 73, 73 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(9) },
  { bp_usNetLed3, SF2_WAN_PORT_NUM, 88, 88 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(24) },
  { bp_usNetLed0, SF2_WAN_PORT_NUM, 74, 74 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(10) },
  { bp_usNetLed1, SF2_WAN_PORT_NUM, 75, 75 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(11) },
  { bp_usNetLed2, SF2_WAN_PORT_NUM, 76, 76 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(12) },
  { bp_usNetLed3, SF2_WAN_PORT_NUM, 89, 89 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(25) },
  { bp_usNetLed0, 1, 80, 80 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(16) },
  { bp_usNetLed1, 1, 81, 81 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(17) },
  { bp_usNetLed3, 1, 91, 91 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(27) },
  { bp_usNetLed0, 0, 77, 77 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(13)},
  { bp_usNetLed1, 0, 78, 78 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(14)},
  { bp_usNetLed2, 0, 79, 79 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(15)},
  { bp_usNetLed3, 0, 90, 90 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(26)},
  { bp_usNetLed0, SF2_WAN_PORT_NUM, 77, 77 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(13)},
  { bp_usNetLed1, SF2_WAN_PORT_NUM, 78, 78 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(14)},
  { bp_usNetLed2, SF2_WAN_PORT_NUM, 79, 79 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(15)},
  { bp_usNetLed3, SF2_WAN_PORT_NUM, 90, 90 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(26)},
  { bp_usGpioLedAggregateLnk, -1, 92, 92 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(28) },
  { bp_usGpioLedAggregateAct, -1, 93, 93 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(29) },
  { bp_usGpioLedWanAct, 0, 94, 94 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(30)},
  { bp_usGpioLedWanAct, 1, 95, 95 | BP_PINMUX_VAL_6 | BP_PINMUX_HWLED | BP_PINMUX_OPTLED_NUM(31)},
  { bp_usGpioLedPwmReserved, -1, 82, 82 | BP_PINMUX_VAL_6 | BP_PINMUX_PWMLED | BP_PINMUX_OPTLED_NUM(18) },
  { bp_usGpioLedPwmReserved, -1, 83, 83 | BP_PINMUX_VAL_6 | BP_PINMUX_PWMLED | BP_PINMUX_OPTLED_NUM(19) },
  { bp_last, -1, -1, 0 },
};

bp_pinmux_defs_t *g_pinmux_defs_tables[] = { g_pinmux_defs_0 } ;

int g_pinmux_fn_defs_size = sizeof(g_pinmux_fn_defs);
