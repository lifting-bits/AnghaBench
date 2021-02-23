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
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int BUFSIZ ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  fatal (int,char*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*,char*) ; 
 char* strerror (int /*<<< orphan*/ ) ; 

void
fatalperror(int f, const char *msg)
{
	char buf[BUFSIZ];

	(void) snprintf(buf, sizeof(buf), "%s: %s", msg, strerror(errno));
	fatal(f, buf);
}