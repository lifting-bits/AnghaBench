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
struct comedi_device {scalar_t__ iobase; } ;

/* Variables and functions */
 scalar_t__ APCI3120_CTR0_REG ; 
 int /*<<< orphan*/  inb (scalar_t__) ; 

__attribute__((used)) static void apci3120_clr_timer2_interrupt(struct comedi_device *dev)
{
	/* a dummy read of APCI3120_CTR0_REG clears the timer 2 interrupt */
	inb(dev->iobase + APCI3120_CTR0_REG);
}