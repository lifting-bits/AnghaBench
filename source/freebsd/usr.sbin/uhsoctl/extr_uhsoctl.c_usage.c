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
 int /*<<< orphan*/  printf (char*,char const*) ; 

__attribute__((used)) static void
usage(const char *exec)
{

	printf("usage %s [-b] [-n] [-a apn] [-c cid] [-p pin] [-u username] "
	    "[-k password] [-r resolvpath] [-f tty] interface\n", exec);
	printf("usage %s -d interface\n", exec);
}