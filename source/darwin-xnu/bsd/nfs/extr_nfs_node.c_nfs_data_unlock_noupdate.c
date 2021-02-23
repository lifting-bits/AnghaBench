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
typedef  int /*<<< orphan*/  nfsnode_t ;

/* Variables and functions */
 int /*<<< orphan*/  nfs_data_unlock_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
nfs_data_unlock_noupdate(nfsnode_t np)
{
	nfs_data_unlock_internal(np, 0);
}