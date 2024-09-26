
#ifndef IOPSYS_PUREUBI_H
#define IOPSYS_PUREUBI_H


//  Iopsys pureUBI with a single large UBI; volume IDs.
#define VOLID_METADATA0     1
#define VOLID_METADATA1     2
#define VOLID_METADATA2     86
#define VOLID_METADATA3     87
#define VOLID_METAINVALID	-1
#define VOLID_UBIFILES0     10
#define VOLID_UBIFILES1     88
#define VOLID_UBIFILES2     90
#define VOLID_UBIFS0        0
#define VOLID_UBIFS1        89
#define VOLID_DATA          99

#define METAVOLID0			(VOLID_METADATA0)
#define METAVOLID1			(VOLID_METADATA1)
#define METAVOLID2			(VOLID_METADATA2)
#define METAVOLID3			(VOLID_METADATA3)
#define BOOTVOL0			(VOLID_UBIFILES0)
#define BOOTVOL1			(VOLID_UBIFILES1)
#define BOOTVOL2			(VOLID_UBIFILES2)
#define ROOTFS0				(VOLID_UBIFS0)
#define ROOTFS1				(VOLID_UBIFS1)
#define DATAVOL				(VOLID_DATA)

#define	UBI_OVERHEAD		4									// UBI internal eraseblocks overhead.
#define	UBIFS_OVERHEAD		17									// UBIFS internal overhead (ubifs-media.h).


#define MAX_METAS			4									// Max number of metadata volumes in the system.
#define METAINVALID			(VOLID_METAINVALID)
#define META2ROOTFS(x)									\
	((x == METAVOLID0 || x == METAVOLID1) ?				\
	ROOTFS0 : (x == METAVOLID2 || x == METAVOLID3) ?	\
	ROOTFS1 : METAINVALID)										// Map meta volumes and corresponding rootfs together.



//----
// Flash block offsets used in CFE.
#define CFE_START_BLK       0
#define CFE_BLKS            8u

#define CFE_RAM_RESCUE_START_BLK       (CFE_START_BLK + CFE_BLKS)
#define CFE_RAM_RESCUE_BLK  8u

#define UBI_START_BLK       32u
#if UBI_START_BLK < CFE_RAM_RESCUE_START_BLK + CFE_RAM_RESCUE_BLK
#error UBI start block is to small!
#endif


#endif
