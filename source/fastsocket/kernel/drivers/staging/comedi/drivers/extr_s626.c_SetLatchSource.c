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
typedef  int uint16_t ;
struct enc_private {int /*<<< orphan*/  MyCRB; } ;
struct comedi_device {int dummy; } ;

/* Variables and functions */
 int CRBBIT_LATCHSRC ; 
 int CRBMSK_INTCTRL ; 
 int CRBMSK_LATCHSRC ; 
 int /*<<< orphan*/  DEBIreplace (struct comedi_device*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  DEBUG (char*) ; 

__attribute__((used)) static void SetLatchSource(struct comedi_device *dev, struct enc_private *k,
			   uint16_t value)
{
	DEBUG("SetLatchSource: SetLatchSource enter 3550 \n");
	DEBIreplace(dev, k->MyCRB,
		    (uint16_t) (~(CRBMSK_INTCTRL | CRBMSK_LATCHSRC)),
		    (uint16_t) (value << CRBBIT_LATCHSRC));

	DEBUG("SetLatchSource: SetLatchSource exit \n");
}