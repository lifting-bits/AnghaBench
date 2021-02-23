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
 int /*<<< orphan*/  Cmd_AddCommand (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Com_Printf (char*,...) ; 
 int /*<<< orphan*/  MAKEWORD (int,int) ; 
 int /*<<< orphan*/  NET_Config (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NET_Restart_f ; 
 int WSAStartup (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qtrue ; 
 int /*<<< orphan*/  winsockInitialized ; 
 int /*<<< orphan*/  winsockdata ; 

void NET_Init( void ) {
#ifdef _WIN32
	int		r;

	r = WSAStartup( MAKEWORD( 1, 1 ), &winsockdata );
	if( r ) {
		Com_Printf( "WARNING: Winsock initialization failed, returned %d\n", r );
		return;
	}

	winsockInitialized = qtrue;
	Com_Printf( "Winsock Initialized\n" );
#endif

	NET_Config( qtrue );
	
	Cmd_AddCommand ("net_restart", NET_Restart_f);
}