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
 char* qdir ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 

char *ExpandPath( const char *path ){
	static char full[1024];
	if ( path[0] == '/' || path[0] == '\\' || path[1] == ':' ) {
		strcpy( full, path );
		return full;
	}
	sprintf( full, "%s%s", qdir, path );
	return full;
}