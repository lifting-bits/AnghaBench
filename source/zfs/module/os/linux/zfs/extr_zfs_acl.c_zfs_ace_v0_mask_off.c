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
 int offsetof (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  z_access_mask ; 
 int /*<<< orphan*/  zfs_oldace_t ; 

__attribute__((used)) static int
zfs_ace_v0_mask_off(void)
{
	return (offsetof(zfs_oldace_t, z_access_mask));
}