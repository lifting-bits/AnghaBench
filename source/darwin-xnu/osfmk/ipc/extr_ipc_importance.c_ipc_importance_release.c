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
typedef  scalar_t__ ipc_importance_elem_t ;

/* Variables and functions */
 scalar_t__ IIE_NULL ; 
 int /*<<< orphan*/  ipc_importance_lock () ; 
 int /*<<< orphan*/  ipc_importance_release_locked (scalar_t__) ; 

void
ipc_importance_release(ipc_importance_elem_t elem)
{
	if (IIE_NULL == elem)
		return;

	ipc_importance_lock();
	ipc_importance_release_locked(elem);
	/* unlocked */
}