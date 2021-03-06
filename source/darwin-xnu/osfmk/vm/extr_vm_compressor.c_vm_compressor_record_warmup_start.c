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
typedef  TYPE_1__* c_segment_t ;
struct TYPE_2__ {scalar_t__ c_generation_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  c_age_list_head ; 
 int /*<<< orphan*/  c_list_lock ; 
 int /*<<< orphan*/  fastwake_recording_in_progress ; 
 scalar_t__ first_c_segment_to_warm_generation_id ; 
 int /*<<< orphan*/  lck_mtx_lock_spin_always (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_unlock_always (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  queue_empty (int /*<<< orphan*/ *) ; 
 scalar_t__ queue_last (int /*<<< orphan*/ *) ; 

void
vm_compressor_record_warmup_start(void)
{
	c_segment_t	c_seg;

	lck_mtx_lock_spin_always(c_list_lock);

	if (first_c_segment_to_warm_generation_id == 0) {
		if (!queue_empty(&c_age_list_head)) {

			c_seg = (c_segment_t)queue_last(&c_age_list_head);

			first_c_segment_to_warm_generation_id = c_seg->c_generation_id;
		} else
			first_c_segment_to_warm_generation_id = 0;

		fastwake_recording_in_progress = TRUE;
	}
	lck_mtx_unlock_always(c_list_lock);
}