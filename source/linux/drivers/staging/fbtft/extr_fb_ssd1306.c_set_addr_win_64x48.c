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
struct fbtft_par {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  write_reg (struct fbtft_par*,int) ; 

__attribute__((used)) static void set_addr_win_64x48(struct fbtft_par *par)
{
	/* Set Column Address */
	write_reg(par, 0x21);
	write_reg(par, 0x20);
	write_reg(par, 0x5F);

	/* Set Page Address */
	write_reg(par, 0x22);
	write_reg(par, 0x0);
	write_reg(par, 0x5);
}