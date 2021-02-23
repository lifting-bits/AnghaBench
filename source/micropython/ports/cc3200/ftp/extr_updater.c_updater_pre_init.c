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

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ OSI_OK ; 
 scalar_t__ sl_LockObjCreate (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  updater_LockObj ; 

__attribute__ ((section (".boot")))
void updater_pre_init (void) {
    // create the updater lock
    ASSERT(OSI_OK == sl_LockObjCreate(&updater_LockObj, "UpdaterLock"));
}