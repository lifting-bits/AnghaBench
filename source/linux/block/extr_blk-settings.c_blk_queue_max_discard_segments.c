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
struct TYPE_2__ {unsigned short max_discard_segments; } ;
struct request_queue {TYPE_1__ limits; } ;

/* Variables and functions */

void blk_queue_max_discard_segments(struct request_queue *q,
		unsigned short max_segments)
{
	q->limits.max_discard_segments = max_segments;
}