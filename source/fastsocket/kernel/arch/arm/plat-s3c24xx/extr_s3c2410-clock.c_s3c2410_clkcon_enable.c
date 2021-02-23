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
struct clk {unsigned int ctrlbit; } ;

/* Variables and functions */
 int /*<<< orphan*/  S3C2410_CLKCON ; 
 unsigned long S3C2410_CLKCON_IDLE ; 
 unsigned long S3C2410_CLKCON_POWER ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,int /*<<< orphan*/ ) ; 

int s3c2410_clkcon_enable(struct clk *clk, int enable)
{
	unsigned int clocks = clk->ctrlbit;
	unsigned long clkcon;

	clkcon = __raw_readl(S3C2410_CLKCON);

	if (enable)
		clkcon |= clocks;
	else
		clkcon &= ~clocks;

	/* ensure none of the special function bits set */
	clkcon &= ~(S3C2410_CLKCON_IDLE|S3C2410_CLKCON_POWER);

	__raw_writel(clkcon, S3C2410_CLKCON);

	return 0;
}