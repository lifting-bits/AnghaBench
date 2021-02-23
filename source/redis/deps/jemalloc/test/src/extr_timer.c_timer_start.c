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
struct TYPE_3__ {int /*<<< orphan*/  t0; } ;
typedef  TYPE_1__ timedelta_t ;

/* Variables and functions */
 int /*<<< orphan*/  nstime_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nstime_update (int /*<<< orphan*/ *) ; 

void
timer_start(timedelta_t *timer) {
	nstime_init(&timer->t0, 0);
	nstime_update(&timer->t0);
}