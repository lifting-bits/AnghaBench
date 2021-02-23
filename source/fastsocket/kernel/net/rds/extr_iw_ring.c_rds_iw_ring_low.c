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
struct rds_iw_work_ring {int w_nr; } ;

/* Variables and functions */
 int __rds_iw_ring_used (struct rds_iw_work_ring*) ; 

int rds_iw_ring_low(struct rds_iw_work_ring *ring)
{
	return __rds_iw_ring_used(ring) <= (ring->w_nr >> 1);
}