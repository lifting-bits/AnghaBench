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
 scalar_t__ connected ; 
 int /*<<< orphan*/  disconnect (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pswitch (int) ; 

void quit(int argc, const char *argv[])
{
	if (connected)
		disconnect(0, NULL);
	pswitch(1);
	if (connected) {
		disconnect(0, NULL);
	}
	exit(0);
}