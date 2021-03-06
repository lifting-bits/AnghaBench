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
 int /*<<< orphan*/  SIG_IGN ; 
 scalar_t__ S_HARD_IGN ; 
 scalar_t__ S_IGN ; 
 int /*<<< orphan*/  setsignal (int) ; 
 scalar_t__* sigmode ; 
 int /*<<< orphan*/  signal (int,int /*<<< orphan*/ ) ; 

void
ignoresig(int signo)
{

	if (sigmode[signo] == 0)
		setsignal(signo);
	if (sigmode[signo] != S_IGN && sigmode[signo] != S_HARD_IGN) {
		signal(signo, SIG_IGN);
		sigmode[signo] = S_IGN;
	}
}