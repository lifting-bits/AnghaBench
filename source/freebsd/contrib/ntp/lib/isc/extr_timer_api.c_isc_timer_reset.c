#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  isc_timertype_t ;
struct TYPE_7__ {TYPE_1__* methods; } ;
typedef  TYPE_2__ isc_timer_t ;
typedef  int /*<<< orphan*/  isc_time_t ;
typedef  int /*<<< orphan*/  isc_result_t ;
typedef  int /*<<< orphan*/  isc_interval_t ;
typedef  int /*<<< orphan*/  isc_boolean_t ;
struct TYPE_6__ {int /*<<< orphan*/  (* reset ) (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ISCAPI_TIMER_VALID (TYPE_2__*) ; 
 int /*<<< orphan*/  REQUIRE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

isc_result_t
isc_timer_reset(isc_timer_t *timer, isc_timertype_t type,
		isc_time_t *expires, isc_interval_t *interval,
		isc_boolean_t purge)
{
	REQUIRE(ISCAPI_TIMER_VALID(timer));

	return (timer->methods->reset(timer, type, expires, interval, purge));
}