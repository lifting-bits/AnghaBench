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
typedef  int /*<<< orphan*/  origtemplate ;

/* Variables and functions */
 int PATH_MAX ; 
 char* absolute_path (char*) ; 
 int /*<<< orphan*/  die_errno (char*,char const*) ; 
 int errno ; 
 int mkstemp (char*) ; 
 int /*<<< orphan*/  strlcpy (char*,char*,int) ; 
 scalar_t__ strlen (char*) ; 

int xmkstemp(char *filename_template)
{
	int fd;
	char origtemplate[PATH_MAX];
	strlcpy(origtemplate, filename_template, sizeof(origtemplate));

	fd = mkstemp(filename_template);
	if (fd < 0) {
		int saved_errno = errno;
		const char *nonrelative_template;

		if (strlen(filename_template) != strlen(origtemplate))
			filename_template = origtemplate;

		nonrelative_template = absolute_path(filename_template);
		errno = saved_errno;
		die_errno("Unable to create temporary file '%s'",
			nonrelative_template);
	}
	return fd;
}