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
 int /*<<< orphan*/  Devices_H_LockUnlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Log_print (char*) ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ devbug ; 

__attribute__((used)) static void Devices_H_Lock(void)
{
	if (devbug)
		Log_print("LOCK Command");
	Devices_H_LockUnlock(TRUE);
}