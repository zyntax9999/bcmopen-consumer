/* Keep Iopsys board params separated from Broadcoms'
 * for easy porting when they release a new SDK version. */

#include "bp_defs.h"
#include "boardparms.h"
#include "bcmSpiRes.h"
#include "boardparms_voice.h"
#include "boardparms_iopsys.h"


//-------------------------------------------------------------
/* Only needed for internal GPHYs; by default internal GPHYs do not adv. 1000HD/100HD/10FD/10HD capabilities;
* There are some NICs that will not negotiate 100FD - so need to advertise 100HD to link up with those NICs */
#define BCM963138_PHY_BASE				0x8



//=============================================================
// PINOUT BOARD PARAMS
//-------------------------------------------------------------
static bp_elem_t g_F104W[] = {
	{bp_cpBoardId,               .u.cp = "F104W"},
	{bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset
	{bp_usGpioReserved,          .u.us = BP_GPIO_33_AL},  // button wps
	{bp_usGpioReserved,          .u.us = BP_GPIO_31_AL},  // LED G.FAST link
	{bp_usGpioReserved,          .u.us = BP_GPIO_58_AL},  // LED G.FAST fail
	{bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},  // LED G.FAST activity
	{bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST | BP_AFE_LD_6303 |BP_AFE_FE_REV_6303_REV_12_3_40 },
	{bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
	{bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
	{bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
	{bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
	{bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
	{bp_usGpioAFELDRelay,        .u.us = BP_GPIO_14_AH},
	{bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

	{bp_ucPhyType0,                  .u.uc = BP_ENET_NO_PHY}, // Runner // switch 0
		{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
		{bp_ucPhyAddress,            .u.uc = 0x1e},
#if defined (USE_RUNNER)
		{bp_ulPortMap,               .u.ul = 0x3},
#else
		{bp_ulPortMap,               .u.ul = 0x2},
#endif

		{bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
#if defined (USE_RUNNER)
			{bp_ulCrossbar,          .u.ul = 13},
			{bp_ulCrossbarPhyId,     .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_6_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_7_AL},
#else   // Dummy config goes nowhere and is not in portmap, not sure its needed.
			{bp_ulCrossbar,          .u.ul = 9},
			{bp_ulCrossbarPhyId,     .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
#endif
		{bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
			{bp_ulPortFlags,         .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch

	{bp_ucPhyType1,                  .u.uc = BP_ENET_EXTERNAL_SWITCH},  // switch 1
		{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},    // Accessing SF2 as MMapped external switch
#if defined (USE_RUNNER)
		{bp_ulPortMap,               .u.ul = 0x7},
#else
		{bp_ulPortMap,               .u.ul = 0xf},
#endif
		{bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_0_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_1_AL},
		{bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_2_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_3_AL},
		{bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_4_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_5_AL},
		{bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
#if  !defined (USE_RUNNER)
		{bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
			{bp_ulCrossbar,          .u.ul = 13},
			{bp_ulCrossbarPhyId,     .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_6_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_7_AL},
#endif
	{bp_ucDspType0,                  .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,                .u.uc = 0},
	{bp_ulMemoryConfig,              .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16| BP_DDR_TEMP_EXTENDED_SRT},
	{bp_last}
};



static bp_elem_t g_DG400R0[] = {
	{bp_cpBoardId,               .u.cp = "DG400R0"},
		{bp_usGpioReserved,      .u.us = BP_GPIO_0_AH}, //Sercomm LED CLK inverted pins, need to handle SH part manually
		{bp_usGpioReserved,      .u.us = BP_GPIO_1_AH}, //Sercomm LED DAT inverted pins, need to handle SH part manually
		{bp_usGpioReserved,      .u.us = BP_GPIO_2_AH}, //Sercomm LED Mask inverted pins, need to handle SH part manually
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
	{bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for voip
	{bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for voip
	{bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_10_AH},  // placeholder for voip
		{bp_usGpioReserved,      .u.us = BP_GPIO_27_AH}, //Sercomm GPIO Status LED green
		{bp_usGpioReserved,      .u.us = BP_GPIO_28_AH}, //Sercomm GPIO Status LED red
		{bp_usGpioReserved,      .u.us = BP_GPIO_16_AH}, //Sercomm PWM LED control
		//{bp_usGpioReserved,    .u.us = BP_GPIO_33_AL}, //Sercomm SX9512 reset
		{bp_usGpioReserved,      .u.us = BP_GPIO_36_AL}, //Sercomm SX9512 interrupt
		{bp_usGpioI2cSda,        .u.us = BP_GPIO_117_AH }, //Sercomm SX9512 I2C SDA
		{bp_usGpioI2cScl,        .u.us = BP_GPIO_119_AH }, //Sercomm SX9512 I2C SCL

	{bp_usGpioReserved,          .u.us = BP_GPIO_108_AL},   // GPHY4_SPD0 (wan_phy_green)
	{bp_usGpioReserved,          .u.us = BP_GPIO_109_AL},   // GPHY4_SPD1 (wan_phy_yellow)
	{bp_usGpioReserved,          .u.us = BP_GPIO_116_AH},   // Eth_LED_CTL
	{bp_usGpioReserved,          .u.us = BP_GPIO_118_AH},   // DECT_Control

	{bp_usGpioDectRst,           .u.us = BP_GPIO_3_AL},
	{bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
	{bp_usButtonIdx,             .u.us = 0},
		{bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
	{bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
	{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
	{bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
	{bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
	{bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
	{bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH},
	{bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH},
	{bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
	{bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
	{bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
	{bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
	{bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
	{bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
	{bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
	{bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
	{bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
	{bp_usSpiSlaveSelectGpioNum, .u.us = 127},
	{bp_usSpiSlaveSelectNum,     .u.us = 2},
	{bp_usSpiSlaveSelectGpioNum, .u.us = 25},
	{bp_usSpiSlaveSelectNum,     .u.us = 4},
	{bp_usSpiSlaveSelectGpioNum, .u.us = 8},
	{bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
	{bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
		{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
		{bp_ucPhyAddress,            .u.uc = 0x1e},
		{bp_ulPortMap,               .u.ul = 0x3},
		{bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
			{bp_ulCrossbar,          .u.ul = 10},
			{bp_ulCrossbarPhyId,     .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			//  {bp_usSpeedLed100,   .u.us = BP_GPIO_108_AL},   // Should have been GPIO 08 or 26 for hw control
			//  {bp_usSpeedLed1000,  .u.us = BP_GPIO_109_AL},   // Should have been GPIO 09 or 27 for hw control
			//  {bp_usLinkLed,       .u.us = BP_GPIO_14_AL},
		{bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
			{bp_ulPortFlags,         .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
			{bp_ucPhyType1,          .u.uc = BP_ENET_EXTERNAL_SWITCH},
			{bp_usConfigType,        .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
			{bp_ulPortMap,           .u.ul = 0x0f},
		{bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_100_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_101_AL},
			//  {bp_usLinkLed,       .u.us = BP_GPIO_28_AL},
		{bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_102_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_103_AL},
			// {bp_usLinkLed,        .u.us = BP_GPIO_11_AL},
		{bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_104_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_105_AL},
			// {bp_usLinkLed,        .u.us = BP_GPIO_12_AL},
		{bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
			{bp_ulCrossbar,          .u.ul = 13},
			{bp_ulCrossbarPhyId,     .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_106_AL},
			{bp_usSpeedLed1000,      .u.us = BP_GPIO_107_AL},
			//  {bp_usLinkLed,       .u.us = BP_GPIO_13_AL},
		//{bp_ulPhyId5,              .u.ul = 0x0  | MAC_IF_RGMII },
		//{bp_ulPhyId7,              .u.ul = 0x19 | MAC_IF_RGMII },
	{bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,            .u.uc = 0},
	{bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB | BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TEMP_EXTENDED_SRT},
	{bp_last}
};



static bp_elem_t g_DG400PRIME[] = {
	{bp_cpBoardId,               .u.cp = "DG400PRIMER0"},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot

	{bp_usGpioReserved,          .u.us = BP_GPIO_133_AH}, // USB0_PWRON USB3.0
	{bp_usGpioReserved,          .u.us = BP_GPIO_135_AH}, // USB1_PWRON USB2.0 (side)

	{bp_usGpioDectRst,           .u.us = BP_GPIO_3_AL},   // DECT_RESET_B
	{bp_usGpioReserved,          .u.us = BP_GPIO_118_AH}, // DECT_Control

	{bp_usGpioReserved,          .u.us = BP_GPIO_33_AL},  // button wifi
	{bp_usGpioReserved,          .u.us = BP_GPIO_34_AL},  // button wps
	{bp_usGpioReserved,          .u.us = BP_GPIO_35_AL},  // button dect

	{bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH},
	{bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH},

	{bp_usGpioReserved,          .u.us = BP_GPIO_76_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_77_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_78_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_79_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_80_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_81_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_82_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_83_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_84_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_85_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_86_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_87_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_88_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_89_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_90_AL}, // LED
	{bp_usGpioReserved,          .u.us = BP_GPIO_91_AL}, // LED

	{bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
	{bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
	{bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
	{bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
	{bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
	{bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
	{bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
	{bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
	{bp_usGpioAFELDRelay,	     .u.us = BP_GPIO_NONE},

	{bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
	{bp_usButtonIdx,             .u.us = 0},
	{  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
	{bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
	//  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  // GPIO_33 + NAND_D1
	{bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH }, // AE_LOS from PCIE

	{bp_usGpioReserved,          .u.us = BP_GPIO_24_AH }, // I2C SDA and sgmii fiber detect seletion for serder interface
	{bp_usGpioReserved,          .u.us = BP_GPIO_25_AH }, // I2C SCL

	{bp_usGpioI2cSda,            .u.us = BP_GPIO_52_AH }, // SX9512 I2C SDA
	{bp_usGpioI2cScl,            .u.us = BP_GPIO_53_AH }, // SX9512 I2C SCL
	//  {bp_usGpioReserved,          .u.us = BP_GPIO_54_AL},  // SX9512 interrupt

	{bp_usSpiSlaveSelectNum,     .u.us = 1},   // FXO1
	{bp_usSpiSlaveSelectGpioNum, .u.us = 127},
	{bp_usSpiSlaveSelectNum,     .u.us = 4},   // FXO2
	{bp_usSpiSlaveSelectGpioNum, .u.us = 8},
	{bp_usSpiSlaveSelectNum,     .u.us = 5},   // FXO3
	{bp_usSpiSlaveSelectGpioNum, .u.us = 7},

	{bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

	{bp_ucPhyType0,                .u.uc = BP_ENET_NO_PHY}, // Runner
		{bp_usConfigType,          .u.us = BP_ENET_CONFIG_MMAP},
		{bp_ucPhyAddress,          .u.uc = 0x1e},
		{bp_ulPortMap,             .u.ul = 0x3},
		{bp_ulPhyId0,              .u.ul = BP_PHY_ID_NOT_SPECIFIED},
		{bp_ulCrossbar,            .u.ul = 9},
			{bp_ulCrossbarPhyId,   .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
		{bp_ulCrossbar,            .u.ul = 10},
			{bp_ulCrossbarPhyId,   .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,     .u.us = BP_GPIO_8_AL},   // indicate 1000bps led
			{bp_usLinkLed,         .u.us = BP_GPIO_14_AL},
		{bp_ulPhyId1,              .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
			{bp_ulPortFlags,       .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
	{bp_ucPhyType1,                .u.uc = BP_ENET_EXTERNAL_SWITCH},
		{bp_usConfigType,          .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
		{bp_ulPortMap,             .u.ul = 0x0f},
		{bp_ulPhyId0,              .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,     .u.us = BP_GPIO_0_AL},
			{bp_usLinkLed,         .u.us = BP_GPIO_10_AL},
		{bp_ulPhyId1,              .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,     .u.us = BP_GPIO_2_AL},
			{bp_usLinkLed,         .u.us = BP_GPIO_11_AL},
		{bp_ulPhyId2,              .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,     .u.us = BP_GPIO_4_AL},
			{bp_usLinkLed,         .u.us = BP_GPIO_12_AL},
		{bp_ulPhyId3,              .u.ul = BP_PHY_ID_NOT_SPECIFIED},
			{bp_ulCrossbar,        .u.ul = 13},
			{bp_ulCrossbarPhyId,   .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,     .u.us = BP_GPIO_6_AL},
			{bp_usLinkLed,         .u.us = BP_GPIO_13_AL},
	{bp_ucDspType0,                .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,              .u.uc = 0},
	{bp_ulMemoryConfig,             .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB | BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TEMP_EXTENDED_SRT},
	{bp_last}
};



static bp_elem_t g_EG400R0[] = {
	{bp_cpBoardId,               .u.cp = "EG400R0"},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot

	{bp_usGpioReserved,          .u.us = BP_GPIO_133_AH}, // USB0_PWRON USB3.0
	{bp_usGpioReserved,          .u.us = BP_GPIO_135_AH}, // USB1_PWRON USB2.0 (side)

	{bp_usGpioDectRst,           .u.us = BP_GPIO_3_AL},   // DECT_RESET_B
	{bp_usGpioReserved,          .u.us = BP_GPIO_118_AH}, // DECT_Control
	{bp_usGpioUart2Sdin,         .u.us = BP_GPIO_22_AH},
	{bp_usGpioUart2Sdout,        .u.us = BP_GPIO_23_AH},

	{bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL},  // pinmux for PWM2 LED (?)

	{bp_usGpioReserved,          .u.us = BP_GPIO_19_AL},  // EXT_GREEN !?
	{bp_usGpioReserved,          .u.us = BP_GPIO_20_AL},  // WIFI_GREEN !?
	{bp_usGpioReserved,          .u.us = BP_GPIO_21_AL},  // WIFI_BLUE !?
	{bp_usGpioReserved,          .u.us = BP_GPIO_107_AL}, // STATUS_RED !?
	{bp_usGpioReserved,          .u.us = BP_GPIO_106_AL}, // STATUS_GREEN !?

	{bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
	{bp_usButtonIdx,             .u.us = 0},
		{bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
	{bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
	{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  // GPIO_33 + NAND_D1 !?
	{bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH }, // AE_LOS from PCIE

	{bp_usGpioReserved,          .u.us = BP_GPIO_24_AH }, // I2C SDA and sgmii fiber detect seletion for serder interface
	{bp_usGpioReserved,          .u.us = BP_GPIO_25_AH }, // I2C SCL

	{bp_usGpioI2cSda,            .u.us = BP_GPIO_52_AH }, // SX9512 I2C SDA
	{bp_usGpioI2cScl,            .u.us = BP_GPIO_53_AH }, // SX9512 I2C SCL
	{bp_usGpioReserved,          .u.us = BP_GPIO_54_AL},  // SX9512 interrupt

	{bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_NONE},

	{bp_usSpiSlaveSelectNum,     .u.us = 1},   // FXO1
	{bp_usSpiSlaveSelectGpioNum, .u.us = 127},
	{bp_usSpiSlaveSelectNum,     .u.us = 4},   // FXO2
	{bp_usSpiSlaveSelectGpioNum, .u.us = 8},
	{bp_usSpiSlaveSelectNum,     .u.us = 5},   // FXO3
	{bp_usSpiSlaveSelectGpioNum, .u.us = 7},

	{bp_usGphyBaseAddress,           .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
	{bp_ucPhyType0,                  .u.uc = BP_ENET_NO_PHY}, // Runner
		{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
		{bp_ucPhyAddress,            .u.uc = 0x1e},
		{bp_ulPortMap,               .u.ul = 0x3},
		{bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
			{bp_ulCrossbar,          .u.ul = 10},
			{bp_ulCrossbarPhyId,     .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			/* use the WAN LED from runner */
			{bp_usSpeedLed100,       .u.us = BP_GPIO_8_AL},   // indicate 1000bps led
			{bp_usLinkLed,           .u.us = BP_GPIO_14_AL},
			{bp_ulCrossbar,          .u.ul = 9},
			{bp_ulCrossbarPhyId,     .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
		{bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
			{bp_ulPortFlags,         .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
			{bp_ucPhyType1,          .u.uc = BP_ENET_EXTERNAL_SWITCH},
			{bp_usConfigType,        .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
			{bp_ulPortMap,           .u.ul = 0x0f},
		{bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_0_AL},
			{bp_usLinkLed,           .u.us = BP_GPIO_10_AL},
		{bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_2_AL},
			{bp_usLinkLed,           .u.us = BP_GPIO_11_AL},
		{bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_4_AL},
			{bp_usLinkLed,           .u.us = BP_GPIO_12_AL},
		{bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
			{bp_ulCrossbar,          .u.ul = 13},
			{bp_ulCrossbarPhyId,     .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
			{bp_usSpeedLed100,       .u.us = BP_GPIO_6_AL},
			{bp_usLinkLed,           .u.us = BP_GPIO_13_AL},
	{bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,            .u.uc = 0},
	{bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB | BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TEMP_EXTENDED_SRT},
	{bp_last}
};



IOPSYSWRT_ADD_G_BOARDPARMS(g_F104W);
IOPSYSWRT_ADD_G_BOARDPARMS(g_DG400R0);
IOPSYSWRT_ADD_G_BOARDPARMS(g_DG400PRIME);
IOPSYSWRT_ADD_G_BOARDPARMS(g_EG400R0);
