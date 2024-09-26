SECTIONS {
  .data : {
    *(.data)
    . = ALIGN(8);

    PROVIDE(g_BoardParms = .);
    KEEP(*(.iopsyswrt_g_BoardParms));
    KEEP(*(.brcm_g_BoardParms));
    /* brcm_g_BoardParms is null-terminated, but add extra NULL just in case */
    KEEP(*(.iopsyswrt_g_BoardParms_terminate));
    PROVIDE(g_BoardParms_end = .);

    PROVIDE(g_VoiceBoardParms = .);
    KEEP(*(.iopsyswrt_g_VoiceBoardParms));
    KEEP(*(.brcm_g_VoiceBoardParms));
    /* brcm_g_VoiceBoardParms is null-terminated, but add extra NULL just in case */
    KEEP(*(.iopsyswrt_g_VoiceBoardParms_terminate));
    PROVIDE(g_VoiceBoardParms_end = .);

    PROVIDE(wlanPaInfo = .);
    KEEP(*(.iopsyswrt_wlanPaInfo));
    KEEP(*(.brcm_wlanPaInfo));
    /* brcm_wlanPaInfo is null-terminated, but add extra termination just in case */
    KEEP(*(.iopsyswrt_wlanPaInfo_terminate));
    PROVIDE(wlanPaInfo_end = .);
  }
}