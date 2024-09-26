
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/kmod.h>
#include <linux/mtd/mtd.h>
#include <linux/jffs2.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/partitions.h>
#include <drivers/mtd/ubi/ubi.h>

#include <bcm_hwdefs.h>
#include <board.h>
#include "iopsys_pureUBI.h"

static struct mtd_partition iopsys_nand_parts[6];



// Return true if flash layout is of old deprecated JFFS2 format.
static int iopsys_has_jffs2_layout(struct mtd_info* mtd)
{
    const int nReqFsBlks = 8;                                                   // Required number fileystem block to consider it "found".
    struct jffs2_raw_inode *jffs2Inode;
    int block, page, nJffs2, nUbi;
    struct ubi_ec_hdr *ubiEc;
    struct nand_chip *chip;
	uint8_t *buf;

    chip = mtd->priv;
    if(!chip || !chip->ecc.read_page)
        return -ENODEV;

    buf = kmalloc(1u << chip->page_shift, GFP_KERNEL);
    jffs2Inode = (struct jffs2_raw_inode*) buf;
    ubiEc = (struct ubi_ec_hdr*) buf;
    page = 0;
    nJffs2 = 0;
    nUbi = 0;

    /* Scan the beginning of the flash where we know the
     * deprecated JFFS2 format store data. Can we find
     * magic identifiers for either JFFS2 or UBI there? */
    for(block = 0; block < 100 && nJffs2 < nReqFsBlks && nUbi < nReqFsBlks; block++) {
        page += (1u << chip->phys_erase_shift) / (1u << chip->page_shift);      // Advance to next erase block.

        *buf = 0;
        chip->cmdfunc(mtd, 0, -1, page);
        if(chip->ecc.read_page(mtd, chip, buf, 0, page))
            continue;

        if(jffs2Inode->magic.v16 == JFFS2_MAGIC_BITMASK &&
                jffs2Inode->nodetype.v16 == JFFS2_NODETYPE_INODE) {
            nJffs2++;
            if(nUbi) nUbi--;
        }
        else if(be32_to_cpu(ubiEc->magic) == UBI_EC_HDR_MAGIC) {
            if(nJffs2) nJffs2--;
            nUbi++;
        }
    }

    kfree(buf);

    // Did we find lots of JFFS2 headers?
    return (nJffs2 >= nReqFsBlks && nUbi < nReqFsBlks);
}



/* Prepare portions of the flash for incorporation it into
 * UBI by erasing them. Only to be used when booting from
 * JFFS2 flash bank 0 (or we will brick the device). */
static int iopsys_prepare_spare(struct mtd_info* mtd)
{
    struct nand_chip *chip;
    int page, endPage;

    // Sanity checks.
    if(!mtd || !mtd->priv || !mtd_type_is_nand(mtd) || mtd->size < 33554432ull)
        return -ENODEV;

    chip = mtd->priv;
    if(!chip || !chip->erase || !iopsys_nand_parts[5].offset ||
            !iopsys_nand_parts[3].offset) {
        return -ENODEV;
    }

    /* Page addresses to unused kernel_1 area. */
    page = iopsys_nand_parts[3].offset / (1ull << chip->page_shift);
    endPage = page + iopsys_nand_parts[0].size / (1ull << chip->page_shift);

    /* Erase consecutive block. Don't care of errors.
     * UBI will later take care of those. */
    while(page < endPage) {
        chip->erase(mtd, page);
        page += (1u << chip->phys_erase_shift) / (1u << chip->page_shift);      // Advance to next erase block.
    }

    /* Page addresses to a small unused area between UBI and BBT.
     * It free for a long time by Iopsys. With Iopsys 5 it becomes
     * incorporated into the large UBI. */
    page = iopsys_nand_parts[5].offset / (1ull << chip->page_shift);
    endPage = page + iopsys_nand_parts[5].size / (1ull << chip->page_shift);

    while(page < endPage) {
        chip->erase(mtd, page);
        page += (1u << chip->phys_erase_shift) / (1u << chip->page_shift);
    }

    return 0;
}



// Check which "bank" CFE has booted.
// Either of 0 or 1.
static unsigned get_flashbank_current(void)
{
    unsigned int cfe_rootfs;
    NVRAM_DATA* nvram;

    nvram = get_inMemNvramData();
    kerSysBlParmsGetInt(NAND_RFS_OFS_NAME, &cfe_rootfs);

    // Which flash "bank"?
    if(cfe_rootfs == nvram->ulNandPartOfsKb[NP_ROOTFS_1]) {
        return 0;
    }
    else if(cfe_rootfs == nvram->ulNandPartOfsKb[NP_ROOTFS_2]) {
        return 1;
    }

    printk("nand: invalid CFE rootfs! Faling back to first.\n");
    return 0;
}



// Generate a kernel command line rootfs argument.
static int iopsys_choose_rootfs(void)
{
    char tmpStr[16];

    snprintf(tmpStr, sizeof(tmpStr), "ubi:rootfs_%u", get_flashbank_current());
    printk("nand: choosing rootfs %s\n", tmpStr);

    kerSysSetBootParm("root=", tmpStr);

    return 0;
}



int iopsys_setup_mtd_parts(struct mtd_info* mtd)
{
    struct nand_chip *chip;
    int res, nPartits;

    chip = mtd->priv;

    if(iopsys_has_jffs2_layout(mtd)) {
        if(get_flashbank_current()) {                                           // Booting from JFFS2 flash bank 1.
            printk("nand: Iopsys found deprecated JFFS2. Preparing migration.\n");

            /* Is flash layout still the old deprecated JFFS2 format? We
             * need to boot anyway. Migration to pure UBI will be done
             * by userspace and next reboot. */
            iopsys_nand_parts[3].name = "nvram";
            iopsys_nand_parts[3].offset = 0*1024;
            iopsys_nand_parts[3].size = 128*1024;
            iopsys_nand_parts[3].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[2].name = "nvram2";
            iopsys_nand_parts[2].offset = iopsys_nand_parts[3].offset + iopsys_nand_parts[3].size;
            iopsys_nand_parts[2].size = 3*128*1024;
            iopsys_nand_parts[2].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[5].name = "cfe_extend";
            iopsys_nand_parts[5].offset = iopsys_nand_parts[2].offset + iopsys_nand_parts[2].size;
            iopsys_nand_parts[5].size = 2*128*1024;
            iopsys_nand_parts[0].name = "kernel_0";
            iopsys_nand_parts[0].offset = iopsys_nand_parts[5].offset + iopsys_nand_parts[5].size;
            iopsys_nand_parts[0].size = 39*128*1024;
            iopsys_nand_parts[0].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[1].name = "kernel_1";
            iopsys_nand_parts[1].offset = iopsys_nand_parts[0].offset + iopsys_nand_parts[0].size;
            iopsys_nand_parts[1].size = 39*128*1024;
            iopsys_nand_parts[1].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[4].name = "ubi";
            iopsys_nand_parts[4].offset = iopsys_nand_parts[1].offset + iopsys_nand_parts[1].size;
            iopsys_nand_parts[4].size = mtd->size -
                iopsys_nand_parts[4].offset - 8*128*1024;
            iopsys_nand_parts[4].ecclayout = mtd->ecclayout;
            nPartits = sizeof(iopsys_nand_parts) / sizeof(struct mtd_partition);
        }
        else {                                                                  // Booting from JFFS2 flash bank 0.
            iopsys_nand_parts[2].name = "nvram";
            iopsys_nand_parts[2].offset = 0*1024;
            iopsys_nand_parts[2].size = 128*1024;
            iopsys_nand_parts[2].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[1].name = "nvram2";
            iopsys_nand_parts[1].offset = iopsys_nand_parts[2].offset + iopsys_nand_parts[2].size;
            iopsys_nand_parts[1].size = 3*128*1024;
            iopsys_nand_parts[1].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[4].name = "cfe_extend";
            iopsys_nand_parts[4].offset = iopsys_nand_parts[1].offset + iopsys_nand_parts[1].size;
            iopsys_nand_parts[4].size = 2*128*1024;
            iopsys_nand_parts[0].name = "kernel_0";
            iopsys_nand_parts[0].offset = iopsys_nand_parts[4].offset + iopsys_nand_parts[4].size;
            iopsys_nand_parts[0].size = 39*128*1024;
            iopsys_nand_parts[0].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[3].name = "ubi";
            iopsys_nand_parts[3].offset = iopsys_nand_parts[0].offset + iopsys_nand_parts[0].size;
            iopsys_nand_parts[3].size = mtd->size -
                iopsys_nand_parts[3].offset - 8*128*1024;
            iopsys_nand_parts[3].ecclayout = mtd->ecclayout;
            iopsys_nand_parts[5].name = "iopspare";
            iopsys_nand_parts[5].offset =
                iopsys_nand_parts[3].offset + iopsys_nand_parts[3].size;
            iopsys_nand_parts[5].size = mtd->size -
                iopsys_nand_parts[5].offset - NAND_BBT_SCAN_MAXBLOCKS * 128 * 1024;
            nPartits = sizeof(iopsys_nand_parts) / sizeof(struct mtd_partition);

            res = iopsys_prepare_spare(mtd);
            if(res)
                return res;
        }

    }
    else {                                                                      // Booting from pureUBI.
        printk("nand: Iopsys found pureUBI layout.\n");

        iopsys_nand_parts[0].name = "nvram";
        iopsys_nand_parts[0].offset = 0;
        iopsys_nand_parts[0].size = (unsigned long long) UBI_START_BLK *
            (1ull << chip->phys_erase_shift);
        iopsys_nand_parts[0].ecclayout = mtd->ecclayout;

        /* Create a UBI partition which span almost the entire
         * flash device. Leave two blocks at the end for MTD BBT. */

        iopsys_nand_parts[1].name = "ubi";
        iopsys_nand_parts[1].offset = iopsys_nand_parts[0].size;
        iopsys_nand_parts[1].size = mtd->size - iopsys_nand_parts[1].offset -
            NAND_BBT_SCAN_MAXBLOCKS * (1ull << chip->phys_erase_shift);
        iopsys_nand_parts[1].ecclayout = mtd->ecclayout;
        nPartits = 2;
    }

    res = mtd_device_register(mtd, iopsys_nand_parts, nPartits);
    if(res)
        return res;

    res = iopsys_choose_rootfs();
    if(res)
        return res;

    return 0;
}
EXPORT_SYMBOL(iopsys_setup_mtd_parts);



// Iopsys pureUBI with a single large UBI. This calculation
// changes the UBI autoresize feature from allocating 100%
// of the available space to 50% of the UBI total size.
// This is used in Iopsys to create two virtual flash "banks"
// of equal size before mounting rootfs for the first time.
int iopsys_calc_ubi_flashbank(struct ubi_device *ubi, int vol_id)
{
	int new_size = (ubi->good_peb_count - ubi->beb_rsvd_pebs -
		UBI_OVERHEAD - MAX_METAS) / 2;

	if (ubi->volumes[DATAVOL])
		new_size -= ubi->volumes[DATAVOL]->reserved_pebs / 2;

	if(vol_id == ROOTFS0 && ubi->volumes[BOOTVOL0] &&
			((ubi->volumes[METAVOLID0] &&
			ubi->volumes[METAVOLID0]->reserved_pebs == 1) ||
			(ubi->volumes[METAVOLID1] &&
			ubi->volumes[METAVOLID1]->reserved_pebs == 1))) {
		new_size -= ubi->volumes[BOOTVOL0]->reserved_pebs;
	}
	else if(vol_id == ROOTFS1 && ubi->volumes[BOOTVOL1] &&
			((ubi->volumes[METAVOLID2] &&
			ubi->volumes[METAVOLID2]->reserved_pebs == 1) ||
			(ubi->volumes[METAVOLID3] &&
			ubi->volumes[METAVOLID3]->reserved_pebs == 1))) {
		new_size -= ubi->volumes[BOOTVOL1]->reserved_pebs;
	}
	else {
		// Fallback to original algorithm for non-Iopsys.
		new_size = ubi->volumes[vol_id]->reserved_pebs + ubi->avail_pebs;
	}

	return new_size;
}
EXPORT_SYMBOL(iopsys_calc_ubi_flashbank);
