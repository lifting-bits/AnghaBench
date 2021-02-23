#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  size_t u_int ;
struct g_raid_volume {scalar_t__ v_state; size_t v_disks_count; struct g_raid_subdisk* v_subdisks; } ;
struct g_raid_tr_object {struct g_raid_volume* tro_volume; } ;
struct g_raid_subdisk {scalar_t__ sd_size; } ;
struct bio_queue_head {int dummy; } ;
struct bio {scalar_t__ bio_cmd; scalar_t__ bio_offset; scalar_t__ bio_length; int bio_flags; char* bio_data; uintptr_t bio_ma_offset; int bio_ma; int bio_ma_n; scalar_t__ bio_error; struct g_raid_subdisk* bio_caller1; } ;
typedef  scalar_t__ off_t ;

/* Variables and functions */
 scalar_t__ BIO_DELETE ; 
 scalar_t__ BIO_FLUSH ; 
 int BIO_UNMAPPED ; 
 scalar_t__ EIO ; 
 scalar_t__ ENOMEM ; 
 scalar_t__ G_RAID_VOLUME_S_OPTIMAL ; 
 scalar_t__ G_RAID_VOLUME_S_SUBOPTIMAL ; 
 int /*<<< orphan*/  KASSERT (int,char*) ; 
 scalar_t__ MIN (scalar_t__,scalar_t__) ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  bioq_init (struct bio_queue_head*) ; 
 int /*<<< orphan*/  bioq_insert_tail (struct bio_queue_head*,struct bio*) ; 
 struct bio* bioq_takefirst (struct bio_queue_head*) ; 
 struct bio* g_clone_bio (struct bio*) ; 
 int /*<<< orphan*/  g_destroy_bio (struct bio*) ; 
 int /*<<< orphan*/  g_raid_iodone (struct bio*,scalar_t__) ; 
 int /*<<< orphan*/  g_raid_subdisk_iostart (struct g_raid_subdisk*,struct bio*) ; 
 int /*<<< orphan*/  g_raid_tr_flush_common (struct g_raid_tr_object*,struct bio*) ; 
 int round_page (scalar_t__) ; 

__attribute__((used)) static void
g_raid_tr_iostart_concat(struct g_raid_tr_object *tr, struct bio *bp)
{
	struct g_raid_volume *vol;
	struct g_raid_subdisk *sd;
	struct bio_queue_head queue;
	struct bio *cbp;
	char *addr;
	off_t offset, length, remain;
	u_int no;

	vol = tr->tro_volume;
	if (vol->v_state != G_RAID_VOLUME_S_OPTIMAL &&
	    vol->v_state != G_RAID_VOLUME_S_SUBOPTIMAL) {
		g_raid_iodone(bp, EIO);
		return;
	}
	if (bp->bio_cmd == BIO_FLUSH) {
		g_raid_tr_flush_common(tr, bp);
		return;
	}

	offset = bp->bio_offset;
	remain = bp->bio_length;
	if ((bp->bio_flags & BIO_UNMAPPED) != 0)
		addr = NULL;
	else
		addr = bp->bio_data;
	no = 0;
	while (no < vol->v_disks_count &&
	    offset >= vol->v_subdisks[no].sd_size) {
		offset -= vol->v_subdisks[no].sd_size;
		no++;
	}
	KASSERT(no < vol->v_disks_count,
	    ("Request starts after volume end (%ju)", bp->bio_offset));
	bioq_init(&queue);
	do {
		sd = &vol->v_subdisks[no];
		length = MIN(sd->sd_size - offset, remain);
		cbp = g_clone_bio(bp);
		if (cbp == NULL)
			goto failure;
		cbp->bio_offset = offset;
		cbp->bio_length = length;
		if ((bp->bio_flags & BIO_UNMAPPED) != 0 &&
		    bp->bio_cmd != BIO_DELETE) {
			cbp->bio_ma_offset += (uintptr_t)addr;
			cbp->bio_ma += cbp->bio_ma_offset / PAGE_SIZE;
			cbp->bio_ma_offset %= PAGE_SIZE;
			cbp->bio_ma_n = round_page(cbp->bio_ma_offset +
			    cbp->bio_length) / PAGE_SIZE;
		} else
			cbp->bio_data = addr;
		cbp->bio_caller1 = sd;
		bioq_insert_tail(&queue, cbp);
		remain -= length;
		if (bp->bio_cmd != BIO_DELETE)
			addr += length;
		offset = 0;
		no++;
		KASSERT(no < vol->v_disks_count || remain == 0,
		    ("Request ends after volume end (%ju, %ju)",
			bp->bio_offset, bp->bio_length));
	} while (remain > 0);
	while ((cbp = bioq_takefirst(&queue)) != NULL) {
		sd = cbp->bio_caller1;
		cbp->bio_caller1 = NULL;
		g_raid_subdisk_iostart(sd, cbp);
	}
	return;
failure:
	while ((cbp = bioq_takefirst(&queue)) != NULL)
		g_destroy_bio(cbp);
	if (bp->bio_error == 0)
		bp->bio_error = ENOMEM;
	g_raid_iodone(bp, bp->bio_error);
}