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
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 

void DefaultPath( char *path, const char *basepath ){
	char temp[128];

	if ( path[ 0 ] == '/' || path[ 0 ] == '\\' ) {
		return;                   // absolute path location
	}
	strcpy( temp,path );
	strcpy( path,basepath );
	strcat( path,temp );
}