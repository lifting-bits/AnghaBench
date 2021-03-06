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
struct TYPE_2__ {int da; int /*<<< orphan*/  cl; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT_CLR ; 
 int /*<<< orphan*/  BIT_SET ; 
 TYPE_1__ bits ; 
 int /*<<< orphan*/  panel_set_bits () ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void lcd_send_serial(int byte)
{
	int bit;

	/* the data bit is set on D0, and the clock on STROBE.
	 * LCD reads D0 on STROBE's rising edge.
	 */
	for (bit = 0; bit < 8; bit++) {
		bits.cl = BIT_CLR;	/* CLK low */
		panel_set_bits();
		bits.da = byte & 1;
		panel_set_bits();
		udelay(2);	/* maintain the data during 2 us before CLK up */
		bits.cl = BIT_SET;	/* CLK high */
		panel_set_bits();
		udelay(1);	/* maintain the strobe during 1 us */
		byte >>= 1;
	}
}