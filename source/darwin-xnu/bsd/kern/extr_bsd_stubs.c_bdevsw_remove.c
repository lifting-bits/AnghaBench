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
struct bdevsw {int dummy; } ;

/* Variables and functions */
 struct bdevsw* bdevsw ; 
 int /*<<< orphan*/  devsw_lock_list_mtx ; 
 int /*<<< orphan*/  lck_mtx_lock_spin (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int nblkdev ; 
 struct bdevsw nobdev ; 

int
bdevsw_remove(int index, struct bdevsw * bsw)
{
	struct bdevsw * devsw;

	if (index < 0 || index >= nblkdev)
		return (-1);

	devsw = &bdevsw[index];
	lck_mtx_lock_spin(&devsw_lock_list_mtx);
	if ((memcmp((char *)devsw, (char *)bsw, sizeof(struct bdevsw)) != 0)) {
		index = -1;
	} else {
		bdevsw[index] = nobdev;
	}
	lck_mtx_unlock(&devsw_lock_list_mtx);
	return (index);
}