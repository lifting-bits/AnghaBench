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
 int /*<<< orphan*/  Discord_ClearPresence () ; 
 int /*<<< orphan*/  Discord_Shutdown () ; 
 int /*<<< orphan*/  RARCH_LOG (char*) ; 
 int discord_ready ; 

void discord_shutdown(void)
{
   RARCH_LOG("[discord] shutting down ..\n");
   Discord_ClearPresence();
   Discord_Shutdown();
   discord_ready = false;
}