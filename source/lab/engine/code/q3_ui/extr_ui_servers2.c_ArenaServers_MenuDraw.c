#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  menu; scalar_t__ refreshservers; } ;

/* Variables and functions */
 int /*<<< orphan*/  ArenaServers_DoRefresh () ; 
 int /*<<< orphan*/  Menu_Draw (int /*<<< orphan*/ *) ; 
 TYPE_1__ g_arenaservers ; 

__attribute__((used)) static void ArenaServers_MenuDraw( void )
{
	if (g_arenaservers.refreshservers)
		ArenaServers_DoRefresh();

	Menu_Draw( &g_arenaservers.menu );
}