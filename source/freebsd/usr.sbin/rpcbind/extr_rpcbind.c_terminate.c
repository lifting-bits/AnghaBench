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
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  _exit (int) ; 
 int doterminate ; 
 int /*<<< orphan*/  terminate_wfd ; 
 int write (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static void
terminate(int signum)
{
	char c = '\0';
	ssize_t wr;

	doterminate = signum;
	wr = write(terminate_wfd, &c, 1);
	if (wr < 1)
		_exit(2);
}