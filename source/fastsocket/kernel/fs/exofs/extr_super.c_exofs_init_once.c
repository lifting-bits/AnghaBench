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
struct exofs_i_info {int /*<<< orphan*/  vfs_inode; } ;

/* Variables and functions */
 int /*<<< orphan*/  inode_init_once (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void exofs_init_once(void *foo)
{
	struct exofs_i_info *oi = foo;

	inode_init_once(&oi->vfs_inode);
}