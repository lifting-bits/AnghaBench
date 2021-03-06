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
struct knote {int dummy; } ;

/* Variables and functions */
 struct tty* tty_from_knote (struct knote*) ; 
 int /*<<< orphan*/  tty_lock (struct tty*) ; 

__attribute__((used)) __attribute__((warn_unused_result))
static struct tty *
tty_lock_from_knote(struct knote *kn)
{
	struct tty *tp = tty_from_knote(kn);
	if (tp) {
		tty_lock(tp);
	}

	return tp;
}