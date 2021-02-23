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
struct ub_event_base {scalar_t__ magic; TYPE_1__* vmt; } ;
struct TYPE_2__ {int (* loopexit ) (struct ub_event_base*,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 scalar_t__ UB_EVENT_MAGIC ; 
 TYPE_1__ default_event_base_vmt ; 
 int /*<<< orphan*/  fptr_ok (int) ; 
 int my_event_base_loopexit (struct ub_event_base*,int /*<<< orphan*/ *) ; 
 int stub1 (struct ub_event_base*,int /*<<< orphan*/ *) ; 

int
ub_event_base_loopexit(struct ub_event_base* base)
{
	if (base->magic == UB_EVENT_MAGIC) {
		fptr_ok(base->vmt != &default_event_base_vmt ||
			base->vmt->loopexit == my_event_base_loopexit);
		return (*base->vmt->loopexit)(base, NULL);
	}
	return -1;
}