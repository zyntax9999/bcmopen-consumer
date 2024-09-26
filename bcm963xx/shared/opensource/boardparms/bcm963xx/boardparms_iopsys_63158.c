/* Keep Iopsys board params separated from Broadcoms'
 * for easy porting when they release a new SDK version. */

#include "bp_defs.h"
#include "boardparms.h"
#include "bcmSpiRes.h"
#include "boardparms_voice.h"
#include "boardparms_iopsys.h"


#define BCM963158_PHY_BASE             0x8


//=============================================================
// PINOUT BOARD PARAMS
//-------------------------------------------------------------

static bp_elem_t g_arcadyan[] = {
  {bp_cpBoardId,               .u.cp = "963158REF_ARC"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND},
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0|BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE|BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_35_AH},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm, .u.ptr = (void*)"Button Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESET | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum, .u.us = BP_GPIO_112_AL},
  {bp_usGphyBaseAddress,       .u.us = BCM963158_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x1}, // ETH WAN related 0x21: bit 0,5 -> bp_ulPhyId0,5
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
#if 0	// eth0 for WAN use
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 9},	// default connected to EXT PHY
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1e | PHY_EXTERNAL | PHY_TYPE_CL45GPHY},
#endif
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x07}, // 0x07: bit 0,1,2,6 for PhyId0,1,2,6
  {bp_ulPhyId0,                .u.ul = (BCM963158_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usOamIndex,              .u.us = 1}, // Fix the index and device name
  {bp_ucPhyDevName,            .u.cp = "eth1"}, // Fix the index and device name
  {bp_ulPhyId1,                .u.ul = (BCM963158_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usOamIndex,              .u.us = 2}, // Fix the index and device name
  {bp_ucPhyDevName,            .u.cp = "eth2"}, // Fix the index and device name
  {bp_ulPhyId2,                .u.ul = (BCM963158_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usOamIndex,              .u.us = 3}, // Fix the index and device name
  {bp_ucPhyDevName,            .u.cp = "eth3"}, // Fix the index and device name
#if 0	// eth4 for LAN use, coexists with eth0 for WAN use bp_ulPhyId5
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},	// default connect to nothing
  {bp_ulCrossbarPhyId, .u.ul = (BCM963158_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
#endif
  {bp_usPcmSdin,               .u.us = BP_GPIO_42_AH},
  {bp_usPcmSdout,              .u.us = BP_GPIO_43_AH},
  {bp_usPcmClk,                .u.us = BP_GPIO_44_AH},
  {bp_usPcmFs,                 .u.us = BP_GPIO_45_AH},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif

#if defined(CONFIG_BP_PHYS_INTF)
  {bp_usIntfId,                .u.us = 0},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_xDSL},
  {bp_usPortNum,               .u.us = 0},
  {bp_ulAfeId,                 .u.ul = BP_AFE_CHIP_GFAST_CH0 | BP_AFE_LD_6305 | BP_AFE_FE_REV_6305_REV_12_5_60_2},
  {bp_usGpioAFELDPwr,          .u.us = BP_GPIO_32_AH}, // Line Driver 0 = "Int"
  {bp_usGpioAFELDData,         .u.us = BP_GPIO_33_AH},
  {bp_usGpioAFELDClk,          .u.us = BP_GPIO_34_AH},
  {bp_usGpioAFELDPwrBoost,     .u.us = BP_GPIO_11_AH},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_22_AH},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 1},	//As BRCM recommands: set the correct value of AFE_ID1
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_xDSL},
  {bp_usPortNum,               .u.us = 1},
  {bp_ulAfeId,                 .u.ul = BP_AFE_CHIP_GFAST_CH1 | BP_AFE_LD_6305 | BP_AFE_FE_REV_6305_REV_12_5_60_1},
  {bp_usIntfEnd},
//secondary definitions for AfeIds
  {bp_usIntfId,                .u.us = 10},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_xDSL},
  {bp_usPortNum,               .u.us = 0},
  {bp_ulAfeId,                 .u.ul = BP_AFE_CHIP_GFAST_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXBJ | BP_AFE_FE_REV_6303_REV_12_3_60},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 2},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_GPHY},
  {bp_usPortNum,               .u.us = 0},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 3},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_GPHY},
  {bp_usPortNum,               .u.us = 1},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 4},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_GPHY},
  {bp_usPortNum,               .u.us = 2},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 5},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_SGMII},
  {bp_usPortNum,               .u.us = SF2_WAN_PORT_NUM}, /* SGMII on EtherWAN port */
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 6},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_xPON},
  {bp_usPortNum,               .u.us = 0},
  {bp_usGpioLedWanLink,        .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usRogueOnuEn,            .u.us = BP_GPIO_40_AH},
  {bp_usIntfMgmtType,          .u.us = BP_INTF_MGMT_TYPE_I2C},
  {bp_usIntfMgmtBusNum,        .u.us = 1},
  {bp_usSfpSigDetect,          .u.us = BP_GPIO_10_AH },
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_39_AH}, /* has a flaw with this pinmux */
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_40_AH},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_5_AL},
  {bp_usGpioLedSim,            .u.us = BP_GPIO_NONE},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_ENABLED | BP_PMD_APD_TYPE_BOOST},
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 7},
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_I2C},
  {bp_usPortNum,               .u.us = 1},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_15_AH }, /* i2c for sgmii optical module */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_16_AH },
  {bp_usIntfEnd},
  {bp_usIntfId,                .u.us = 8}, /* UART for DECT */
  {bp_usIntfType,              .u.us = BP_INTF_TYPE_UART},
  {bp_usPortNum,               .u.us = 1},
  {bp_usUartSdin,              .u.us = BP_GPIO_25_AH},
  {bp_usUartSdout,             .u.us = BP_GPIO_24_AH},
  {bp_usIntfEnd},
#endif
  {bp_usUsbPwrOn0,             .u.us = BP_GPIO_122_AH},
  {bp_usUsbPwrFlt0,            .u.us = BP_GPIO_121_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1},
  {bp_ulPciFlags,              .u.ul = BP_PCI0_DUAL_LANE},
  {bp_last}
};



IOPSYSWRT_ADD_G_BOARDPARMS(g_arcadyan);
