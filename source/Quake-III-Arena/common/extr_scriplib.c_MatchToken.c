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
 int /*<<< orphan*/  Error (char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetToken (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qtrue ; 
 int /*<<< orphan*/  scriptline ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  token ; 

void MatchToken( char *match ) {
	GetToken( qtrue );

	if ( strcmp( token, match ) ) {
		Error( "MatchToken( \"%s\" ) failed at line %i", match, scriptline );
	}
}