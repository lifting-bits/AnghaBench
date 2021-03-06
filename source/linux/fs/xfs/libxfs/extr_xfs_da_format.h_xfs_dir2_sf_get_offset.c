#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  offset; } ;
typedef  TYPE_1__ xfs_dir2_sf_entry_t ;
typedef  int /*<<< orphan*/  xfs_dir2_data_aoff_t ;

/* Variables and functions */
 int /*<<< orphan*/  get_unaligned_be16 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline xfs_dir2_data_aoff_t
xfs_dir2_sf_get_offset(xfs_dir2_sf_entry_t *sfep)
{
	return get_unaligned_be16(sfep->offset);
}