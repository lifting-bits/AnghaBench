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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int expect_close ; 
 int /*<<< orphan*/  pr_crit (char*) ; 
 int /*<<< orphan*/  timer_alive ; 
 int /*<<< orphan*/  wdt_keepalive () ; 
 int /*<<< orphan*/  wdt_stop () ; 

__attribute__((used)) static int wdt_release(struct inode *inode, struct file *file)
{
	/*
	 * Shut off the timer.
	 * Lock it in if it's a module and we set nowayout
	 */
	if (expect_close == 42) {
		wdt_stop();
		clear_bit(0, &timer_alive);
	} else {
		wdt_keepalive();
		pr_crit("unexpected close, not stopping watchdog!\n");
	}
	expect_close = 0;
	return 0;
}