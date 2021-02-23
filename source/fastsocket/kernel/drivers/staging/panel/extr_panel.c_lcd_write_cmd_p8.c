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
struct TYPE_2__ {void* e; void* rw; void* rs; } ;

/* Variables and functions */
 void* BIT_CLR ; 
 void* BIT_SET ; 
 TYPE_1__ bits ; 
 int /*<<< orphan*/  pprt ; 
 int /*<<< orphan*/  pprt_lock ; 
 int /*<<< orphan*/  set_ctrl_bits () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  w_dtr (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void lcd_write_cmd_p8(int cmd)
{
	spin_lock(&pprt_lock);
	/* present the data to the data port */
	w_dtr(pprt, cmd);
	udelay(20);		/* maintain the data during 20 us before the strobe */

	bits.e = BIT_SET;
	bits.rs = BIT_CLR;
	bits.rw = BIT_CLR;
	set_ctrl_bits();

	udelay(40);		/* maintain the strobe during 40 us */

	bits.e = BIT_CLR;
	set_ctrl_bits();

	udelay(120);		/* the shortest command takes at least 120 us */
	spin_unlock(&pprt_lock);
}