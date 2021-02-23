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
struct tty {int dummy; } ;

/* Variables and functions */
 int OFWCONS_POLL_HZ ; 
 int /*<<< orphan*/  callout_reset (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,struct tty*) ; 
 int hz ; 
 int /*<<< orphan*/  ofw_timeout ; 
 int /*<<< orphan*/  ofw_timer ; 
 int polltime ; 

__attribute__((used)) static int
ofwtty_open(struct tty *tp)
{
	polltime = hz / OFWCONS_POLL_HZ;
	if (polltime < 1)
		polltime = 1;

	callout_reset(&ofw_timer, polltime, ofw_timeout, tp);

	return (0);
}