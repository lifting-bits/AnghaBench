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
typedef  TYPE_1__* vm_object_t ;
typedef  scalar_t__ boolean_t ;
struct TYPE_3__ {int /*<<< orphan*/  Lock_owner; int /*<<< orphan*/  Lock; } ;

/* Variables and functions */
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  current_thread () ; 
 scalar_t__ lck_rw_try_lock_exclusive (int /*<<< orphan*/ *) ; 

boolean_t
_vm_object_lock_try(vm_object_t object)
{
	boolean_t	retval;

	retval = lck_rw_try_lock_exclusive(&object->Lock);
#if DEVELOPMENT || DEBUG
	if (retval == TRUE)
		object->Lock_owner = current_thread();
#endif
	return (retval);
}