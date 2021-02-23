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
 char* POSTSIGTERM_WARN ; 
 int auditwarnlog (char**) ; 

int
audit_warn_postsigterm(void)
{
	char *args[2];

	args[0] = POSTSIGTERM_WARN;
	args[1] = NULL;

	return (auditwarnlog(args));
}