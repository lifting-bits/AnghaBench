#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct list_head {int dummy; } ;
struct buffer_head {unsigned long b_size; int /*<<< orphan*/  b_link; int /*<<< orphan*/ * b_data; scalar_t__ b_bcb; scalar_t__ b_blocknr; struct block_device* b_bdev; } ;
struct block_device {int /*<<< orphan*/  bd_bh_lock; TYPE_1__* bd_priv; } ;
typedef  scalar_t__ sector_t ;
typedef  int /*<<< orphan*/  s64 ;
struct TYPE_8__ {int /*<<< orphan*/  bh_count; } ;
struct TYPE_7__ {int /*<<< orphan*/  QuadPart; } ;
struct TYPE_6__ {int /*<<< orphan*/  Volume; } ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  TYPE_1__* PEXT2_VCB ;
typedef  TYPE_2__ LARGE_INTEGER ;
typedef  int ERESOURCE_THREAD ;

/* Variables and functions */
 int /*<<< orphan*/  BLOCK_BITS ; 
 int /*<<< orphan*/  CcPinRead (int /*<<< orphan*/ ,TYPE_2__*,unsigned long,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CcPreparePinWrite (int /*<<< orphan*/ ,TYPE_2__*,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CcSetBcbOwnerPointer (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DEBUG (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  DL_BH ; 
 int /*<<< orphan*/  DbgBreak () ; 
 int /*<<< orphan*/  ExAcquireResourceExclusiveLite (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExAcquireSharedStarveExclusive (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExReleaseResourceLite (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Ext2Sleep (int) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  InitializeListHead (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PIN_WAIT ; 
 int /*<<< orphan*/  RemoveEntryList (int /*<<< orphan*/ *) ; 
 scalar_t__ TOTAL_BLOCKS ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  buffer_head_insert (struct block_device*,struct buffer_head*) ; 
 struct buffer_head* buffer_head_search (struct block_device*,scalar_t__) ; 
 int /*<<< orphan*/  free_buffer_head (struct buffer_head*) ; 
 TYPE_3__ g_jbh ; 
 int /*<<< orphan*/  get_bh (struct buffer_head*) ; 
 struct buffer_head* new_buffer_head () ; 
 int /*<<< orphan*/  set_buffer_uptodate (struct buffer_head*) ; 

struct buffer_head *
get_block_bh_pin(
    struct block_device *   bdev,
    sector_t                block,
    unsigned long           size,
    int                     zero
) 
{
    PEXT2_VCB Vcb = bdev->bd_priv;
    LARGE_INTEGER offset;

    struct list_head *entry;

    /* allocate buffer_head and initialize it */
    struct buffer_head *bh = NULL, *tbh = NULL;

    /* check the block is valid or not */
    if (block >= TOTAL_BLOCKS) {
        DbgBreak();
        goto errorout;
    }

    /* search the bdev bh list */
    ExAcquireSharedStarveExclusive(&bdev->bd_bh_lock, TRUE);
    tbh = buffer_head_search(bdev, block);
    if (tbh) {
        bh = tbh;
        get_bh(bh);
        ExReleaseResourceLite(&bdev->bd_bh_lock);
        goto errorout;
    }
    ExReleaseResourceLite(&bdev->bd_bh_lock);

    bh = new_buffer_head();
    if (!bh) {
        goto errorout;
    }
    bh->b_bdev = bdev;
    bh->b_blocknr = block;
    bh->b_size = size;
    bh->b_data = NULL;
#ifdef __REACTOS__
    InitializeListHead(&bh->b_link);
#endif

again:

    offset.QuadPart = (s64) bh->b_blocknr;
    offset.QuadPart <<= BLOCK_BITS;

    if (zero) {
        if (!CcPreparePinWrite(Vcb->Volume,
                            &offset,
                            bh->b_size,
                            FALSE,
                            PIN_WAIT,
                            &bh->b_bcb,
                            (PVOID *)&bh->b_data)) {
            Ext2Sleep(100);
            goto again;
        }
    } else {
        if (!CcPinRead( Vcb->Volume,
                        &offset,
                        bh->b_size,
                        PIN_WAIT,
                        &bh->b_bcb,
                        (PVOID *)&bh->b_data)) {
            Ext2Sleep(100);
            goto again;
        }
        set_buffer_uptodate(bh);
    }

    if (bh->b_bcb)
        CcSetBcbOwnerPointer(bh->b_bcb, (PVOID)((ERESOURCE_THREAD)bh | 0x3));

    if (!bh->b_data) {
        free_buffer_head(bh);
        bh = NULL;
        goto errorout;
    }
    get_bh(bh);

    DEBUG(DL_BH, ("getblk: Vcb=%p bhcount=%u block=%u bh=%p ptr=%p.\n",
                  Vcb, atomic_read(&g_jbh.bh_count), block, bh, bh->b_data));

    ExAcquireResourceExclusiveLite(&bdev->bd_bh_lock, TRUE);
    /* do search again here */
    tbh = buffer_head_search(bdev, block);
    if (tbh) {
        get_bh(tbh);
        free_buffer_head(bh);
        bh = tbh;
        RemoveEntryList(&bh->b_link);
        InitializeListHead(&bh->b_link);
        ExReleaseResourceLite(&bdev->bd_bh_lock);
        goto errorout;
    } else {
        buffer_head_insert(bdev, bh);
    }
    ExReleaseResourceLite(&bdev->bd_bh_lock);

    /* we get it */
errorout:

    return bh;
}