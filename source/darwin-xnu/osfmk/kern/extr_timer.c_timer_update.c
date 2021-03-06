#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
typedef  TYPE_1__* timer_t ;
struct TYPE_4__ {scalar_t__ tstamp; } ;

/* Variables and functions */
 int /*<<< orphan*/  timer_advance (TYPE_1__*,scalar_t__) ; 

void
timer_update(timer_t timer, uint64_t tstamp)
{
	timer_advance(timer, tstamp - timer->tstamp);
	timer->tstamp = tstamp;
}