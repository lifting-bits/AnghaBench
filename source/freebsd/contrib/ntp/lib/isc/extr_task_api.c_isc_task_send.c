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
typedef  int /*<<< orphan*/  isc_event_t ;
struct TYPE_6__ {int /*<<< orphan*/  (* send ) (TYPE_2__*,int /*<<< orphan*/ **) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ENSURE (int /*<<< orphan*/ ) ; 
 int ISCAPI_TASK_VALID (TYPE_2__*) ; 
 int /*<<< orphan*/  REQUIRE (int) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,int /*<<< orphan*/ **) ; 

void
isc_task_send(isc_task_t *task, isc_event_t **eventp) {
	REQUIRE(ISCAPI_TASK_VALID(task));
	REQUIRE(eventp != NULL && *eventp != NULL);

	task->methods->send(task, eventp);

	ENSURE(*eventp == NULL);
}