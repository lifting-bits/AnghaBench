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
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int MAXPATHLEN ; 
 int /*<<< orphan*/  NOCATGETS (char*) ; 
 int /*<<< orphan*/  dummy ; 
 int /*<<< orphan*/  sd ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/  vim_snprintf (char*,int,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  write (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

void workshop_file_opened(char *filename, int readOnly)
{
	char buffer[2*MAXPATHLEN];
	vim_snprintf(buffer, sizeof(buffer),
			NOCATGETS("loadedFile %s %d\n"), filename, readOnly);
	dummy = write(sd, buffer, strlen(buffer));
}