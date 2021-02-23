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
 int /*<<< orphan*/  qprintf (char*,...) ; 

GlobUsage( char *szItem, int itemstorage, int maxstorage )
{
	float	percentage = maxstorage ? itemstorage * 100.0 / maxstorage : 0.0;

	qprintf("%-12s     [variable]    %7i/%-7i  (%4.1f%%)", 
				szItem, itemstorage, maxstorage, percentage );
	if ( percentage > 80.0 )
		qprintf( "VERY FULL!\n" );
	else if ( percentage > 95.0 )
		qprintf( "SIZE DANGER!\n" );
	else if ( percentage > 99.9 )
		qprintf( "SIZE OVERFLOW!!!\n" );
	else
		qprintf( "\n" );
	return itemstorage;
}