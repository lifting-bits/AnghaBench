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
struct skl_dev {struct skl_debug* debugfs; } ;
struct skl_debug {int /*<<< orphan*/  fs; } ;

/* Variables and functions */
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ ) ; 

void skl_debugfs_exit(struct skl_dev *skl)
{
	struct skl_debug *d = skl->debugfs;

	debugfs_remove_recursive(d->fs);

	d = NULL;
}