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

/* Variables and functions */
 int /*<<< orphan*/  OP_MOUNT ; 
 int share_mount (int /*<<< orphan*/ ,int,char**) ; 

__attribute__((used)) static int
zfs_do_mount(int argc, char **argv)
{
	return (share_mount(OP_MOUNT, argc, argv));
}