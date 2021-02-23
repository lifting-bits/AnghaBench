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
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 int /*<<< orphan*/  Exec_UnlistenAllCommit () ; 
 int /*<<< orphan*/  asyncQueueUnregister () ; 

__attribute__((used)) static void
Async_UnlistenOnExit(int code, Datum arg)
{
	Exec_UnlistenAllCommit();
	asyncQueueUnregister();
}