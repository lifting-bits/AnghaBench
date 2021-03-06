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
struct TYPE_3__ {int /*<<< orphan*/ * locks; } ;
typedef  TYPE_1__ rrmlock_t ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 int RRM_NUM_LOCKS ; 
 int /*<<< orphan*/  rrw_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void
rrm_init(rrmlock_t *rrl, boolean_t track_all)
{
	int i;

	for (i = 0; i < RRM_NUM_LOCKS; i++)
		rrw_init(&rrl->locks[i], track_all);
}