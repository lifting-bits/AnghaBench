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
struct seq_softc {int /*<<< orphan*/  timerstop; scalar_t__ timerrun; } ;

/* Variables and functions */
 int /*<<< orphan*/  getmicrotime (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
timer_stop(struct seq_softc *t)
{
	t->timerrun = 0;
	getmicrotime(&t->timerstop);
}