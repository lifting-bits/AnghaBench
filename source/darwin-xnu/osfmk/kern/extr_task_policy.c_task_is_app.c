#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_2__* task_t ;
typedef  int /*<<< orphan*/  boolean_t ;
struct TYPE_4__ {int trp_apptype; } ;
struct TYPE_5__ {TYPE_1__ requested_policy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
#define  TASK_APPTYPE_APP_DEFAULT 129 
#define  TASK_APPTYPE_APP_TAL 128 
 int /*<<< orphan*/  TRUE ; 

boolean_t
task_is_app(task_t task)
{
	switch (task->requested_policy.trp_apptype) {
	case TASK_APPTYPE_APP_DEFAULT:
	case TASK_APPTYPE_APP_TAL:
		return TRUE;
	default:
		return FALSE;
	}
}