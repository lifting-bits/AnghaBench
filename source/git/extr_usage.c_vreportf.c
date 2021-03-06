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
typedef  int /*<<< orphan*/  va_list ;
typedef  int /*<<< orphan*/  msg ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,char*) ; 
 scalar_t__ iscntrl (char) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  vsnprintf (char*,int,char const*,int /*<<< orphan*/ ) ; 

void vreportf(const char *prefix, const char *err, va_list params)
{
	char msg[4096];
	char *p;

	vsnprintf(msg, sizeof(msg), err, params);
	for (p = msg; *p; p++) {
		if (iscntrl(*p) && *p != '\t' && *p != '\n')
			*p = '?';
	}
	fprintf(stderr, "%s%s\n", prefix, msg);
}