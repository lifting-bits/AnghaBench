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
struct xfs_owner_info {scalar_t__ oi_owner; } ;

/* Variables and functions */
 scalar_t__ XFS_RMAP_OWN_NULL ; 

__attribute__((used)) static inline bool
xfs_rmap_should_skip_owner_update(
	const struct xfs_owner_info	*oi)
{
	return oi->oi_owner == XFS_RMAP_OWN_NULL;
}