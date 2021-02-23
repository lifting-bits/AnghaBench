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
struct TYPE_7__ {TYPE_1__* methods; } ;
typedef  TYPE_2__ isc_task_t ;
typedef  int /*<<< orphan*/  isc_eventtype_t ;
struct TYPE_6__ {unsigned int (* purgeevents ) (TYPE_2__*,void*,int /*<<< orphan*/ ,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ISCAPI_TASK_VALID (TYPE_2__*) ; 
 int /*<<< orphan*/  REQUIRE (int /*<<< orphan*/ ) ; 
 unsigned int stub1 (TYPE_2__*,void*,int /*<<< orphan*/ ,void*) ; 

unsigned int
isc_task_purge(isc_task_t *task, void *sender, isc_eventtype_t type, void *tag)
{
	REQUIRE(ISCAPI_TASK_VALID(task));

	return (task->methods->purgeevents(task, sender, type, tag));
}