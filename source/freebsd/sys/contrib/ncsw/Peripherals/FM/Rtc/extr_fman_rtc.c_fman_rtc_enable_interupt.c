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
typedef  int uint32_t ;
struct rtc_regs {int dummy; } ;

/* Variables and functions */
 int fman_rtc_get_interrupt_mask (struct rtc_regs*) ; 
 int /*<<< orphan*/  fman_rtc_set_interrupt_mask (struct rtc_regs*,int) ; 

void fman_rtc_enable_interupt(struct rtc_regs *regs, uint32_t events)
{
	fman_rtc_set_interrupt_mask(regs, fman_rtc_get_interrupt_mask(regs) | events);
}