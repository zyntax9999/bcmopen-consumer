
/* Keep Iopsys board params separated from Broadcoms'
 * for easy porting when they release a new SDK version. */

#include "bp_defs.h"
#include "boardparms.h"
#include "bcmSpiRes.h"
#include "boardparms_voice.h"
#include "boardparms_iopsys.h"


#if defined(_CFE_)
#include "lib_types.h"
#include "lib_string.h"
#include "lib_printf.h"
#define printk printf
#else
#include <linux/kernel.h>
#endif // _CFE_

//=============================================================
// WiFi SROM
//-------------------------------------------------------------
static WLAN_SROM_ENTRY wlan_patch_unique_963268BU[] = {
	{2,  0x5A7},
	{65, 0x1201},
	{0, 0}
};



static WLAN_SROM_ENTRY wlan_patch_common_963138REF[] = {
	{ 66,  0x200},
	{ 68,  0x9800},
	{ 87,  0x41f},
	{ 96,  0x204A},
	{ 97,  0xFE9B}, 
	{ 98,  0x17D5},
	{ 99,  0xFAAD},
	{ 112, 0x204A},
	{ 113, 0xFE74},
	{ 114, 0x1646},
	{ 115, 0xFAC2},
	{ 162, 0x4444},
	{ 170, 0x4444},
	{ 172, 0x4444},
	{0, 0}
};



static WLAN_SROM_ENTRY wlan_patch_unique_DG400R0[] = {
	{79,  0x0000},
	{80,  0x0000},
	{87,  0x0415},
	{96,  0x204a},
	{97,  0xfe48},
	{98,  0x14c8},
	{99,  0xfab7},
	{112, 0x204a},
	{113, 0xfe92},
	{114, 0x1688},
	{115, 0xfa9b},
	{161, 0x2200},
	{162, 0x4442},
	{169, 0x4222},
	{170, 0x6644},
	{171, 0x4222},
	{172, 0x6644},
	{173, 0x4222},
	{174, 0x6644},
	{175, 0x4222},
	{176, 0x6644},
	{0, 0}
};



static WLAN_SROM_ENTRY wlan_patch_unique_EG400R0[] = {
	{ 97,  0xFE6d},
	{ 98,  0x17f9},
	{ 99,  0xFA40},
	{ 113, 0xFE65},
	{ 114, 0x180a},
	{ 115, 0xFA2e},
	{0, 0}
};



static WLAN_SROM_ENTRY wlan_patch_common_EG400[] = { {0, 0}
};



static WLAN_SROM_ENTRY wlan_patch_common_F104W[] = {
		{ 97, 0xfe53},
		{ 98, 0x152f},
		{ 99, 0xfaa2},
		{ 113, 0xfea6},
		{ 114, 0x1832},
		{ 115, 0xfa59},
		{0, 0}
};



static WLAN_SROM_ENTRY wlan_patch_unique_F104W[] = { {0, 0}
};



/* The common part contains the entries that are valid for multiple boards */
static WLAN_SROM_ENTRY wlan_patch_common_963268MBV[] = {
	{ 78,  0x0303}, 
	{ 79,  0x0202}, 
	{ 80,  0xff02},
	{ 87,  0x0315}, 
	{ 88,  0x0315},
	{ 94,  0x001E},
	{ 96,  0x2048}, 
	{ 97,  0xFFB5}, 
	{ 98,  0x175F},
	{ 99,  0xFB29},
	{ 100, 0x3E40},
	{ 101, 0x403C},
	{ 102, 0xFF15},
	{ 103, 0x1455},
	{ 104, 0xFB95},
	{ 108, 0xFF28},
	{ 109, 0x1315},
	{ 110, 0xFBF0},
	{ 112, 0x2048},
	{ 113, 0xFFD7},
	{ 114, 0x17D6},
	{ 115, 0xFB67},
	{ 116, 0x3E40},
	{ 117, 0x403C},
	{ 118, 0xFE87},
	{ 119, 0x110F},
	{ 120, 0xFB4B},
	{ 124, 0xFF8D},
	{ 125, 0x1146},
	{ 126, 0xFCD6},
	{ 161, 0x0000},
	{ 162, 0x4444},
	{ 163, 0x0000},
	{ 164, 0x2222},
	{ 165, 0x0000},
	{ 166, 0x2222},
	{ 167, 0x0000},
	{ 168, 0x2222},
	{ 169, 0x4000},
	{ 170, 0x4444},
	{ 171, 0x4000},
	{ 172, 0x4444},
	{ 177, 0x2000},
	{ 178, 0x2222},
	{ 179, 0x2000},
	{ 180, 0x2222},
	{ 185, 0x2000},
	{ 186, 0x2222},
	{ 187, 0x2000},
	{ 188, 0x2222},
	{ 193, 0x2000},
	{ 194, 0x2222},
	{ 195, 0x2000},
	{ 196, 0x2222},
	{ 201, 0x1111},
	{ 202, 0x2222},
	{ 203, 0x4446},
	{0, 0}
};


IOPSYSWRT_ADD_WLANPAINFO("DG301R0",        0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV);
IOPSYSWRT_ADD_WLANPAINFO("DG400R0",        0xa8d1, 220, wlan_patch_unique_DG400R0,       wlan_patch_common_963138REF);
IOPSYSWRT_ADD_WLANPAINFO("EG400R0",        0xa8d1, 220, wlan_patch_unique_EG400R0,       wlan_patch_common_EG400);
IOPSYSWRT_ADD_WLANPAINFO("F104W",          0xa8d1, 220, wlan_patch_unique_F104W,         wlan_patch_common_F104W);



//=============================================================
// VOICE BOARD PARAMS
//-------------------------------------------------------------
extern VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_NOSLIC;
extern VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_SI32176;
extern VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_LE9661_ZSI_BB;
extern VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_SI32260_LCQC;
extern BP_VOICE_CHANNEL_INTERNAL g_iDectStdCfg[];


// Dual Si32260_LCQC voice channels and external Dect.
static VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_SI32260_LCQC_and_extern_Dect = {
	VOICECFG_SI32260_LCQC_STR,   /*Daughter card ID */
	{
		{
			BP_VD_EDECT1,              /* deviceType */
			BP_VDTYPE_PCM,             /* audioType */
			BP_SPI_SS_NOT_REQUIRED,    /* SPI_SS_Bx */
			BP_RESET_NOT_REQUIRED,     /* rstPin (only implemeted for Slic) */
			{                          /* channel[] */
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(0, 1) ),
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(2, 3) ),
			}
		},
		{
			BP_VD_EDECT1,              /* deviceType */
			BP_VDTYPE_PCM,             /* audioType */
			BP_SPI_SS_NOT_REQUIRED,    /* SPI_SS_Bx */
			BP_RESET_NOT_REQUIRED,     /* rstPin (only implemeted for Slic) */
			{                          /* channel[] */
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(4, 5) ),
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(6, 7) ),
			}
		},
		{
			/* Device Type */
			BP_VD_SILABS_32261,
			BP_VDTYPE_PCM,
			BP_SPI_SS_B1,  /* Device uses SPI_SS_B1 pin. Pin on base board depends on base board parameters. */
			BP_RESET_FXS1, /* Device uses FXS1 reset pin. Pin on base board depends on base board parameters. */
			{
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_SLIC, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(8, 9) ),
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_SLIC, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(10, 11) ),
			}
		},
		/* Always end device list with this macro. */
		BP_NULL_DEVICE_MACRO,
	},
	/* SLIC Device Profile */
	BP_VD_LCQCUK,
	/* General-purpose flags */
	BP_FLAG_DSP_PCMHAL_ENABLE
};



// Dual SI32176 with one channel each.
static VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_SI32176x2 = {
	VOICECFG_SI32176X2_STR,   /*Daughter Card ID */
	{
		{
			/* Device Type */
			BP_VD_SILABS_32176,
			BP_VDTYPE_PCM,
			BP_SPI_SS_B1,  /* Device uses SPI_SS_B1 pin. Pin on base board depends on base board parameters. */
			BP_RESET_FXS1, /* Device uses FXS1 reset pin. Pin on base board depends on base board parameters. */
			/* Channel description */
			{
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_SLIC, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(0, 1) ),
				BP_CHAN( BP_VC_INACTIVE, BP_VCTYPE_NONE, BP_VC_COMP_LINEAR, BP_VC_8KHZ ),
			}
		},
		{
			/* Device Type 2 */
			BP_VD_SILABS_32176,
			BP_VDTYPE_PCM,
			BP_SPI_SS_B2,  /* Device uses SPI_SS_B2 pin. Pin on base board depends on base board parameters. */
			BP_RESET_FXS2, /* Device uses FXS2 reset pin. Pin on base board depends on base board parameters. */
			/* Channel description */
			{
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_SLIC, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(2, 3) ),
				BP_CHAN( BP_VC_INACTIVE, BP_VCTYPE_NONE, BP_VC_COMP_LINEAR, BP_VC_8KHZ ),
			}
		},
	
		BP_NULL_DEVICE_MACRO,
	},
	/* SLIC Device Profile */
	BP_VD_FLYBACK,
	/* General-purpose flags */
	BP_FLAG_DSP_PCMHAL_ENABLE
};



// Dual ZL88801 voice channels and external Dect.
static VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_ZL88801_and_extern_Dect = {
	VOICECFG_ZL88801_STR,
	{
		{
			BP_VD_EDECT1,              /* deviceType */
			BP_VDTYPE_PCM,             /* audioType */
			BP_SPI_SS_NOT_REQUIRED,    /* SPI_SS_Bx */
			BP_RESET_NOT_REQUIRED,     /* rstPin (only implemeted for Slic) */
			{                          /* channel[] */
			BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(0, 1) ),
			BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(2, 3) ),
			}
		},
		{
			BP_VD_EDECT1,              /* deviceType */
			BP_VDTYPE_PCM,             /* audioType */
			BP_SPI_SS_NOT_REQUIRED,    /* SPI_SS_Bx */
			BP_RESET_NOT_REQUIRED,     /* rstPin (only implemeted for Slic) */
			{                          /* channel[] */
			BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(4, 5) ),
			BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_DECT, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(6, 7) ),
			}
		},
		{
			/* Device Type */
			BP_VD_ZARLINK_88801,
			BP_VDTYPE_PCM,
			BP_SPI_SS_B1,  /* Device uses SPI_SS_B1 pin. Pin on base board depends on base board parameters. */
			BP_RESET_FXS1, /* Device uses FXS1 reset pin. Pin on base board depends on base board parameters. */
			{
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_SLIC, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(8, 9) ),
				BP_CHAN_PCM( BP_VC_ACTIVE, BP_VCTYPE_SLIC, BP_VC_COMP_LINEAR, BP_VC_8KHZ, TS(10, 11) ),
			}
		},
		/* Always end device list with this macro. */
		BP_NULL_DEVICE_MACRO,
	},
	/* SLIC Device Profile */
	BP_VD_BUCKBOOST,
	/* General-purpose flags */
	BP_FLAG_DSP_PCMHAL_ENABLE
};



static VOICE_DAUGHTER_BOARD_PARMS g_voiceBoard_intern_Dect_only = {
	VOICECFG_DECT_ONLY_STR,   /*Daughter Card ID */
	{
		BP_NULL_DEVICE_MACRO
	},	
	/* SLIC Device Profile */
	BP_NOT_DEFINED,
	/* General-purpose flags */
	0
};



static VOICE_DAUGHTER_BOARD_PARMS *g_dCardList_Iopsys_dual_or_no_FXS_intern_or_no_Dect[] = {
	&g_voiceBoard_NOSLIC,
	&g_voiceBoard_intern_Dect_only,
	&g_voiceBoard_SI32176,
	&g_voiceBoard_SI32176x2,
	&g_voiceBoard_LE9661_ZSI_BB,
	0
};



static VOICE_DAUGHTER_BOARD_PARMS *g_dCardList_Iopsys_dual_or_no_FXS_extern_or_no_Dect[] = {
	&g_voiceBoard_NOSLIC,
	&g_voiceBoard_SI32260_LCQC_and_extern_Dect,
	&g_voiceBoard_ZL88801_and_extern_Dect,
	0
};



static bp_elem_t g_voice_bcmDG301R0[] = {
	{bp_cpBoardId,               .u.cp = "DG301R0"},
	{bp_usFxsFxo1SpiSSNum,       .u.us = SPI_DEV_1},
	{bp_usFxsFxo2SpiSSNum,       .u.us = SPI_DEV_4},
	{bp_usFxsFxo3SpiSSNum,       .u.us = SPI_DEV_5},
	{bp_usGpioFxsFxoRst1,        .u.us = BP_GPIO_13_AL},
	{bp_usGpioFxsFxoRst2,        .u.us = BP_GPIO_14_AL},
	{bp_usGpioDectRst,           .u.us = BP_GPIO_18_AL},
	{bp_usGpioVoipRelayCtrl1,    .u.us = BP_GPIO_8_AH},
	{bp_iDectCfg,                .u.ptr = g_iDectStdCfg},
	{bp_daughterCardList,        .u.ptr = g_dCardList_Iopsys_dual_or_no_FXS_intern_or_no_Dect},
	{bp_last}
};



static bp_elem_t g_voice_DG400R0[] = {
	{bp_cpBoardId,               .u.cp = "DG400R0"},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_PCM},
	{bp_usFxsFxo1SpiSSNum,       .u.us = SPI_DEV_1},
	{bp_usFxsFxo2SpiSSNum,       .u.us = SPI_DEV_2},
	{bp_usFxsFxo3SpiSSNum,       .u.us = SPI_DEV_4},
	{bp_usGpioFxsFxoRst1,        .u.us = BP_GPIO_4_AL},
	{bp_usGpioFxsFxoRst2,        .u.us = BP_NOT_DEFINED},
	{bp_usGpioFxsFxoRst3,        .u.us = BP_NOT_DEFINED},
	{bp_usGpioVoipRelayCtrl1,    .u.us = BP_NOT_DEFINED},
	{bp_daughterCardList,        .u.ptr = g_dCardList_Iopsys_dual_or_no_FXS_extern_or_no_Dect},
	{bp_last}
};

static bp_elem_t g_voice_DG400PRIMER0[] = {
	{bp_cpBoardId,               .u.cp = "DG400PRIMER0"},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_PCM},
	{bp_usFxsFxo1SpiSSNum,       .u.us = SPI_DEV_5},
	{bp_usGpioFxsFxoRst1,        .u.us = BP_GPIO_4_AL},
	{bp_usGpioFxsFxoRst2,        .u.us = BP_NOT_DEFINED},
	{bp_usGpioFxsFxoRst3,        .u.us = BP_NOT_DEFINED},
	{bp_usGpioVoipRelayCtrl1,    .u.us = BP_NOT_DEFINED},
	{bp_daughterCardList,        .u.ptr = g_dCardList_Iopsys_dual_or_no_FXS_extern_or_no_Dect},
	{bp_last}
};

static bp_elem_t g_voice_F104W[] = {
	{bp_cpBoardId,               .u.cp = "F104W"},
	{bp_daughterCardList,        .u.ptr = g_dCardList_Iopsys_dual_or_no_FXS_extern_or_no_Dect},
	{bp_last}
};

static bp_elem_t g_voice_EG400R0[] = {
	{bp_cpBoardId,               .u.cp = "EG400R0"},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_PCM},
	{bp_usFxsFxo1SpiSSNum,       .u.us = SPI_DEV_1},
	{bp_usFxsFxo2SpiSSNum,       .u.us = SPI_DEV_4},
	{bp_usFxsFxo3SpiSSNum,       .u.us = SPI_DEV_5},
	{bp_usGpioFxsFxoRst1,        .u.us = BP_GPIO_5_AL},
	{bp_usGpioFxsFxoRst2,        .u.us = BP_NOT_DEFINED},
	{bp_usGpioFxsFxoRst3,        .u.us = BP_NOT_DEFINED},
	{bp_usGpioVoipRelayCtrl1,    .u.us = BP_NOT_DEFINED},
	{bp_daughterCardList,        .u.ptr = g_dCardList_Iopsys_dual_or_no_FXS_extern_or_no_Dect},
	{bp_last}
};



IOPSYSWRT_ADD_G_VOICEBOARDPARMS(g_voice_bcmDG301R0);
IOPSYSWRT_ADD_G_VOICEBOARDPARMS(g_voice_DG400R0);
IOPSYSWRT_ADD_G_VOICEBOARDPARMS(g_voice_DG400PRIMER0);
IOPSYSWRT_ADD_G_VOICEBOARDPARMS(g_voice_F104W);
IOPSYSWRT_ADD_G_VOICEBOARDPARMS(g_voice_EG400R0);

static WLAN_SROM_ENTRY wlan_patch_empty[] = {
       {0, 0}
};

WLAN_SROM_PATCH_INFO wlanPaInfoTerminate __attribute__((__section__(".iopsyswrt_wlanPaInfo_terminate"))) = {
	"", 0, 0, wlan_patch_empty, wlan_patch_empty};
bp_elem_t *g_VoiceBoardParmsTerminate  __attribute__((__section__(".iopsyswrt_g_VoiceBoardParms_terminate"))) = NULL;
bp_elem_t *g_BoardParmsTerminate __attribute__((__section__(".iopsyswrt_g_BoardParms_terminate"))) = NULL;
