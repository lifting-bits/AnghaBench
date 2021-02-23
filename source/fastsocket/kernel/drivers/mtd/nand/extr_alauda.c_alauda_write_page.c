#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct mtd_info {int writesize; struct alauda* priv; } ;
struct alauda_sg_request {int /*<<< orphan*/ ** urb; int /*<<< orphan*/  comp; } ;
struct alauda {int pagemask; int port; int /*<<< orphan*/  card_mutex; int /*<<< orphan*/  write_out; int /*<<< orphan*/  dev; int /*<<< orphan*/  bulk_out; TYPE_1__* card; } ;
typedef  int loff_t ;
struct TYPE_2__ {int blockshift; int pageshift; } ;

/* Variables and functions */
 int ALAUDA_BULK_CMD ; 
 int ALAUDA_BULK_WRITE_PAGE ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_NOIO ; 
 int PBA_HI (int) ; 
 int PBA_LO (int) ; 
 int PBA_ZONE (int) ; 
 int /*<<< orphan*/  TIMEOUT ; 
 int /*<<< orphan*/  alauda_complete ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * usb_alloc_urb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_fill_bulk_urb (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_free_urb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_kill_urb (int /*<<< orphan*/ *) ; 
 int usb_submit_urb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int alauda_write_page(struct mtd_info *mtd, loff_t to, void *buf,
		void *oob)
{
	struct alauda_sg_request sg;
	struct alauda *al = mtd->priv;
	u32 pba = to >> al->card->blockshift;
	u32 page = (to >> al->card->pageshift) & al->pagemask;
	u8 command[] = {
		ALAUDA_BULK_CMD, ALAUDA_BULK_WRITE_PAGE, PBA_HI(pba),
		PBA_ZONE(pba), 0, PBA_LO(pba) + page, 32, 0, al->port
	};
	int i, err;

	for (i=0; i<3; i++)
		sg.urb[i] = NULL;

	err = -ENOMEM;
	for (i=0; i<3; i++) {
		sg.urb[i] = usb_alloc_urb(0, GFP_NOIO);
		if (!sg.urb[i])
			goto out;
	}
	init_completion(&sg.comp);
	usb_fill_bulk_urb(sg.urb[0], al->dev, al->bulk_out, command, 9,
			alauda_complete, NULL);
	usb_fill_bulk_urb(sg.urb[1], al->dev, al->write_out, buf,mtd->writesize,
			alauda_complete, NULL);
	usb_fill_bulk_urb(sg.urb[2], al->dev, al->write_out, oob, 16,
			alauda_complete, &sg.comp);

	mutex_lock(&al->card_mutex);
	for (i=0; i<3; i++) {
		err = usb_submit_urb(sg.urb[i], GFP_NOIO);
		if (err)
			goto cancel;
	}
	if (!wait_for_completion_timeout(&sg.comp, TIMEOUT)) {
		err = -ETIMEDOUT;
cancel:
		for (i=0; i<3; i++) {
			usb_kill_urb(sg.urb[i]);
		}
	}
	mutex_unlock(&al->card_mutex);

out:
	usb_free_urb(sg.urb[0]);
	usb_free_urb(sg.urb[1]);
	usb_free_urb(sg.urb[2]);
	return err;
}