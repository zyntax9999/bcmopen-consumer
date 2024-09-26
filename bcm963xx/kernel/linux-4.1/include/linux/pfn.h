#ifndef _LINUX_PFN_H_
#define _LINUX_PFN_H_

#ifndef __ASSEMBLY__
#include <linux/types.h>
#endif

#define PFN_ALIGN(x)	(((unsigned long)(x) + (PAGE_SIZE - 1)) & PAGE_MASK)
#define PFN_UP(x)	(((x) + PAGE_SIZE-1) >> PAGE_SHIFT)
#define PFN_DOWN(x)	((x) >> PAGE_SHIFT)
#define PFN_PHYS(x)	((phys_addr_t)(x) << PAGE_SHIFT)
#if defined(CONFIG_BCM_KF_MISC_BACKPORTS)
/* this definition is missing in 4.1.y, needs to be brought
   from master branch
*/
#define PHYS_PFN(x)    ((unsigned long)((x) >> PAGE_SHIFT))
#endif

#endif
