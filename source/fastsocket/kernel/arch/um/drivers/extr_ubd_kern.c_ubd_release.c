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
struct ubd {scalar_t__ count; } ;
struct gendisk {struct ubd* private_data; } ;
typedef  int /*<<< orphan*/  fmode_t ;

/* Variables and functions */
 int /*<<< orphan*/  ubd_close_dev (struct ubd*) ; 

__attribute__((used)) static int ubd_release(struct gendisk *disk, fmode_t mode)
{
	struct ubd *ubd_dev = disk->private_data;

	if(--ubd_dev->count == 0)
		ubd_close_dev(ubd_dev);
	return 0;
}