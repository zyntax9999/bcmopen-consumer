#if defined(CONFIG_BCM96368)
#elif defined(CONFIG_BCM96362)
#elif defined(CONFIG_BCM96328)
#elif defined(CONFIG_BCM963268)
#if defined(SUPPORT_DSL_BONDING)
#define ADSL_PHY_SDRAM_BIAS 0x080000
#define ADSL_PHY_SDRAM_PAGE_SIZE 0x200000
#else
#define ADSL_PHY_SDRAM_BIAS 0x0CE000
#define ADSL_PHY_SDRAM_PAGE_SIZE 0x200000
#endif
#elif defined(CONFIG_BCM963381)
#define ADSL_PHY_SDRAM_BIAS 0x0CE000
#define ADSL_PHY_SDRAM_PAGE_SIZE 0x200000
#elif defined(CONFIG_BCM963138)
#define ADSL_PHY_SDRAM_BIAS 0x500000
#define ADSL_PHY_SDRAM_PAGE_SIZE 0x800000
#elif defined(CONFIG_BCM963148)
#define ADSL_PHY_SDRAM_BIAS 0x010000
#define ADSL_PHY_SDRAM_PAGE_SIZE 0x200000
#elif defined(CONFIG_BCM963158)
#define ADSL_PHY_SDRAM_BIAS 0x100000
#define ADSL_PHY_SDRAM_PAGE_SIZE 0x400000
#else
#define ADSL_PHY_SDRAM_BIAS 0x100000
#define ADSL_PHY_SDRAM_PAGE_SIZE 0x200000
#endif
#define ADSL_SDRAM_IMAGE_SIZE (ADSL_PHY_SDRAM_PAGE_SIZE - ADSL_PHY_SDRAM_BIAS)
