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
typedef  scalar_t__ u32 ;
struct ecore_hwfn {int dummy; } ;
struct ecore_bmap {scalar_t__ max_count; int /*<<< orphan*/  name; int /*<<< orphan*/  bitmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  DP_NOTICE (struct ecore_hwfn*,int,char*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  DP_VERBOSE (struct ecore_hwfn*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ECORE_MSG_RDMA ; 
 int /*<<< orphan*/  OSAL_SET_BIT (scalar_t__,int /*<<< orphan*/ ) ; 

void ecore_bmap_set_id(struct ecore_hwfn *p_hwfn,
		       struct ecore_bmap *bmap,
		       u32		id_num)
{
	if (id_num >= bmap->max_count) {
		DP_NOTICE(p_hwfn, true,
			  "%s bitmap: cannot set id %d max is %d\n",
			  bmap->name, id_num, bmap->max_count);

		return;
	}

	OSAL_SET_BIT(id_num, bmap->bitmap);

	DP_VERBOSE(p_hwfn, ECORE_MSG_RDMA, "%s bitmap: set id %d\n",
		   bmap->name, id_num);
}