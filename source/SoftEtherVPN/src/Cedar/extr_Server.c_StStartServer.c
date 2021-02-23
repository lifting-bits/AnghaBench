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
 int /*<<< orphan*/  Lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SiNewServer (int) ; 
 int /*<<< orphan*/  Unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * server ; 
 int /*<<< orphan*/  server_lock ; 

void StStartServer(bool bridge)
{
	Lock(server_lock);
	{
		if (server != NULL)
		{
			// It has already started
			Unlock(server_lock);
			return;
		}

		// Create a server
		server = SiNewServer(bridge);
	}
	Unlock(server_lock);

//	StartCedarLog();
}