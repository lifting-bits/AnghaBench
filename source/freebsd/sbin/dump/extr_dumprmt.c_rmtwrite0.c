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
typedef  int /*<<< orphan*/  line ;

/* Variables and functions */
 int /*<<< orphan*/  rmtape ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/  write (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

void
rmtwrite0(int count)
{
	char line[30];

	(void)snprintf(line, sizeof (line), "W%d\n", count);
	write(rmtape, line, strlen(line));
}