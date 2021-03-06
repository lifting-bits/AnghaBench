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
struct TYPE_2__ {scalar_t__ cdev; } ;
struct ubifs_info {TYPE_1__ vi; } ;
struct super_block {struct ubifs_info* s_fs_info; } ;
typedef  scalar_t__ dev_t ;

/* Variables and functions */

__attribute__((used)) static int sb_test(struct super_block *sb, void *data)
{
	dev_t *dev = data;
	struct ubifs_info *c = sb->s_fs_info;

	return c->vi.cdev == *dev;
}