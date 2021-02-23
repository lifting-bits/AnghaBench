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

/* Variables and functions */
 int errno ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,...) ; 
 char* progname ; 
 int /*<<< orphan*/  stderr ; 
 char* strerror (int) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  vfprintf (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
whine(const char *type, const char *format, va_list ap)
{
	int error = errno;

	fprintf(stderr, "%s: %s: ", type, progname);
	vfprintf(stderr, format, ap);

	if (format[strlen(format) - 1] != '\n')
		fprintf(stderr, ": %s\n", strerror(error));
}