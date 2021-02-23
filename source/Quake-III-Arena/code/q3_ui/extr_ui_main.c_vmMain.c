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
 int UI_API_VERSION ; 
#define  UI_CONSOLE_COMMAND 138 
 int UI_ConsoleCommand (int) ; 
#define  UI_DRAW_CONNECT_SCREEN 137 
 int /*<<< orphan*/  UI_DrawConnectScreen (int) ; 
#define  UI_GETAPIVERSION 136 
#define  UI_HASUNIQUECDKEY 135 
#define  UI_INIT 134 
#define  UI_IS_FULLSCREEN 133 
 int /*<<< orphan*/  UI_Init () ; 
 int UI_IsFullscreen () ; 
#define  UI_KEY_EVENT 132 
 int /*<<< orphan*/  UI_KeyEvent (int,int) ; 
#define  UI_MOUSE_EVENT 131 
 int /*<<< orphan*/  UI_MouseEvent (int,int) ; 
#define  UI_REFRESH 130 
 int /*<<< orphan*/  UI_Refresh (int) ; 
#define  UI_SET_ACTIVE_MENU 129 
#define  UI_SHUTDOWN 128 
 int /*<<< orphan*/  UI_SetActiveMenu (int) ; 
 int /*<<< orphan*/  UI_Shutdown () ; 
 int qtrue ; 

int vmMain( int command, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11  ) {
	switch ( command ) {
	case UI_GETAPIVERSION:
		return UI_API_VERSION;

	case UI_INIT:
		UI_Init();
		return 0;

	case UI_SHUTDOWN:
		UI_Shutdown();
		return 0;

	case UI_KEY_EVENT:
		UI_KeyEvent( arg0, arg1 );
		return 0;

	case UI_MOUSE_EVENT:
		UI_MouseEvent( arg0, arg1 );
		return 0;

	case UI_REFRESH:
		UI_Refresh( arg0 );
		return 0;

	case UI_IS_FULLSCREEN:
		return UI_IsFullscreen();

	case UI_SET_ACTIVE_MENU:
		UI_SetActiveMenu( arg0 );
		return 0;

	case UI_CONSOLE_COMMAND:
		return UI_ConsoleCommand(arg0);

	case UI_DRAW_CONNECT_SCREEN:
		UI_DrawConnectScreen( arg0 );
		return 0;
	case UI_HASUNIQUECDKEY:				// mod authors need to observe this
		return qtrue;  // bk010117 - change this to qfalse for mods!
	}

	return -1;
}