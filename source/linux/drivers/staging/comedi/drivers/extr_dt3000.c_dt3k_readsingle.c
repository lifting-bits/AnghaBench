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
struct comedi_device {scalar_t__ mmio; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPR_CMD_READSINGLE ; 
 scalar_t__ DPR_PARAMS (int) ; 
 scalar_t__ DPR_SUBSYS ; 
 int /*<<< orphan*/  dt3k_send_cmd (struct comedi_device*,int /*<<< orphan*/ ) ; 
 unsigned int readw (scalar_t__) ; 
 int /*<<< orphan*/  writew (unsigned int,scalar_t__) ; 

__attribute__((used)) static unsigned int dt3k_readsingle(struct comedi_device *dev,
				    unsigned int subsys, unsigned int chan,
				    unsigned int gain)
{
	writew(subsys, dev->mmio + DPR_SUBSYS);

	writew(chan, dev->mmio + DPR_PARAMS(0));
	writew(gain, dev->mmio + DPR_PARAMS(1));

	dt3k_send_cmd(dev, DPR_CMD_READSINGLE);

	return readw(dev->mmio + DPR_PARAMS(2));
}