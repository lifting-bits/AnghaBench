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
 int /*<<< orphan*/  R_FATAL ; 
 int /*<<< orphan*/  report (int /*<<< orphan*/ ,char*) ; 
 char* strdup (char const*) ; 

char *xstrdup( const char *str )
{
    char *res = strdup( str );
    if (!res) report (R_FATAL, "Out of memory.");
    return res;
}