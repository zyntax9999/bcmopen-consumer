
#ifndef BOARDPARAM_IOPSYS_H
#define BOARDPARAM_IOPSYS_H

#include "bp_defs.h"


//-------------------------------------------------------------
/* Voice Daughtercard defines */
#define VOICECFG_DECT_ONLY_STR         "DECT_ONLY"
#define VOICECFG_ZL88801_STR           "ZL88801"
#define VOICECFG_SI32176X2_STR         "SI32176X2"
#define VOICECFG_SI32260_QC_STR        "SI32260_QC"

//-------------------------------------------------------------
// Ensure these don't colide with BP_OVERLAY_xx by Broadcom!
#define BP_OVERLAY_USB_POWER			(1u << 30)
#define BP_OVERLAY_DG301			(1u << 31)

/*
Since boardparms_voice.c mixes the definition of the g_VoiceBoardParms with
functions making use of that global variable, we cannot easily solve this
with objcopy- and linker-script-magic and we have no choice but to patch
the source and solve conflicts on every new release :-(
Provide this macro for placing the Broadcom brcm_g_VoiceBoardParms into an
ELF section where the linker-script can find it.
*/
#define SECTION_BRCM_G_VOICEBOARDPARMS __attribute__((__section__(".brcm_g_VoiceBoardParms")))

/*
The name actually does not matter at all, so we could just use __COUNTER__
to get a unique name, but for easier debugging we define a nice readable
name where possible. The name can be seem for example in:

GDB (at runtime, where 0xdeadbeef is a memory address):
    (gdb) info symbol 0xdeadbeef

objdump (offline, where someFile is an object-file or a linked ELF such as
bcm963xx/cfe/build/broadcom/bcm63xx_ram/cfe$(BRCM_CHIP) or
bcm963xx/shared/opensource/boardparms/bcm963xx/built-in.o

    $ objdump --syms someFile | sort | grep -E  'BoardParms|PaInfo'

This has the downside that "variable" needs to be a valid C identifier,
so one cannot use "complex" expressions like 5+5 or array[1].
*/
#define IOP_UNIQUE_NAME_(section, variable, line, counter) \
		add_ ## variable ## _to_ ## section ## _l ## line ## c ## counter
#define IOP_UNIQUE_NAME(section, variable, line, counter) IOP_UNIQUE_NAME_(section, variable, line, counter)

#define IOPSYSWRT_ADD_TO_SECTION_(type, section_name, unique_name, value) \
		type const unique_name  __attribute__((__section__(#section_name))) = value


/*
The following IOPSYSWRT_ADD_* macros can be used by multiple compilation units
to add an entry to the corresponding array enabling adding new boardparms
without patching the bcmkernel.

Implementation detail: This is achieved by creating variables and putting them
all in the same ELF-section and treating the whole section as an array.
Since the original Broadcom arrays are NULL terminated and we put our entries
in front of BRCM ones, we can do this without changing a lot of Broadcom code.
*/


/*
Add an entry to the bp_elem_t * g_BoardParms[] array.
Argument needs to be a variable name (type bp_elem_t* or bp_elem_t[]).
*/
#define IOPSYSWRT_ADD_G_BOARDPARMS(bp_elem_t_ptr)\
		IOPSYSWRT_ADD_TO_SECTION_( \
			bp_elem_t *, \
			.iopsyswrt_g_BoardParms, \
			IOP_UNIQUE_NAME(iopsyswrt_g_BoardParms, bp_elem_t_ptr, __LINE__, __COUNTER__), \
			bp_elem_t_ptr \
			)

/*
Add an entry to the bp_elem_t * g_VoiceBoardParms[] array.
Argument needs to be a variable name (type bp_elem_t* or bp_elem_t[]).
*/
#define IOPSYSWRT_ADD_G_VOICEBOARDPARMS(bp_elem_t_ptr)\
		IOPSYSWRT_ADD_TO_SECTION_( \
			bp_elem_t *, \
			.iopsyswrt_g_VoiceBoardParms, \
			IOP_UNIQUE_NAME(iopsyswrt_g_VoiceBoardParms, bp_elem_t_ptr, __LINE__, __COUNTER__), \
			bp_elem_t_ptr \
			)

#define IOP_BRACES5(a,b,c,d,e) {a,b,c,d,e}

/*
Adds an entry to the WLAN_SROM_PATCH_INFO wlanPaInfo[] array.
Arguments are initializations of the members of WLAN_SROM_PATCH_INFO.
*/
#define IOPSYSWRT_ADD_WLANPAINFO(boardId, usWirelessChipId, usNeededSize, uniqueEntries, commonEntries)\
		IOPSYSWRT_ADD_TO_SECTION_( \
			WLAN_SROM_PATCH_INFO, \
			.iopsyswrt_wlanPaInfo, \
			IOP_UNIQUE_NAME(iopsyswrt_wlanPaInfo, _, __LINE__, __COUNTER__), \
			IOP_BRACES5(boardId, usWirelessChipId, usNeededSize, uniqueEntries, commonEntries) \
		)

/*
Variant to define a custom name to work around potential naming conflicts.
We still want to support boardIds with - in them, so we can't use boardId in
a variable name.
*/
#define IOPSYSWRT_ADD_WLANPAINFO_VARNAME(varName, boardId, usWirelessChipId, usNeededSize, uniqueEntries, commonEntries)\
		IOPSYSWRT_ADD_TO_SECTION_( \
			WLAN_SROM_PATCH_INFO, \
			.iopsyswrt_wlanPaInfo, \
			IOP_UNIQUE_NAME(iopsyswrt_wlanPaInfo, varName, __LINE__, __COUNTER__), \
			IOP_BRACES5(boardId, usWirelessChipId, usNeededSize, uniqueEntries, commonEntries) \
		)

#endif
