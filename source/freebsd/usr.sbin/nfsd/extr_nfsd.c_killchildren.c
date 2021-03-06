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
 int /*<<< orphan*/  SIGKILL ; 
 scalar_t__* children ; 
 int /*<<< orphan*/  kill (scalar_t__,int /*<<< orphan*/ ) ; 
 int nfsdcnt ; 

__attribute__((used)) static void
killchildren(void)
{
	int i;

	for (i = 0; i < nfsdcnt; i++) {
		if (children[i] > 0)
			kill(children[i], SIGKILL);
	}
}