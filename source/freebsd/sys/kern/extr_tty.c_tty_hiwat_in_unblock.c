#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int c_iflag; scalar_t__* c_cc; } ;
struct tty {int t_flags; TYPE_1__ t_termios; int /*<<< orphan*/  t_outq; } ;

/* Variables and functions */
 int IXOFF ; 
 int TF_HIWAT_IN ; 
 size_t VSTART ; 
 scalar_t__ _POSIX_VDISABLE ; 
 int /*<<< orphan*/  tty_gone (struct tty*) ; 
 int /*<<< orphan*/  ttydevsw_inwakeup (struct tty*) ; 
 scalar_t__ ttyoutq_write_nofrag (int /*<<< orphan*/ *,scalar_t__*,int) ; 

void
tty_hiwat_in_unblock(struct tty *tp)
{

	if (tp->t_flags & TF_HIWAT_IN &&
	    tp->t_termios.c_iflag & IXOFF &&
	    tp->t_termios.c_cc[VSTART] != _POSIX_VDISABLE) {
		/*
		 * Input flow control. Only leave the high watermark when we
		 * can successfully store the VSTART character.
		 */
		if (ttyoutq_write_nofrag(&tp->t_outq,
		    &tp->t_termios.c_cc[VSTART], 1) == 0)
			tp->t_flags &= ~TF_HIWAT_IN;
	} else {
		/* No input flow control. */
		tp->t_flags &= ~TF_HIWAT_IN;
	}

	if (!tty_gone(tp))
		ttydevsw_inwakeup(tp);
}