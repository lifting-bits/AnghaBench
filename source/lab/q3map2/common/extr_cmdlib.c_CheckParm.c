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
 int /*<<< orphan*/  Q_stricmp (char const*,int /*<<< orphan*/ ) ; 
 int myargc ; 
 int /*<<< orphan*/ * myargv ; 

int CheckParm( const char *check ){
	int i;

	for ( i = 1; i < myargc; i++ )
	{
		if ( !Q_stricmp( check, myargv[i] ) ) {
			return i;
		}
	}

	return 0;
}