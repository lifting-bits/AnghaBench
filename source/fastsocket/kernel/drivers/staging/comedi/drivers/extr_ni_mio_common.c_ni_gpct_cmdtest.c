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
struct ni_gpct {int dummy; } ;
struct comedi_subdevice {struct ni_gpct* private; } ;
struct comedi_device {int dummy; } ;
struct comedi_cmd {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 int ni_tio_cmdtest (struct ni_gpct*,struct comedi_cmd*) ; 

__attribute__((used)) static int ni_gpct_cmdtest(struct comedi_device *dev,
			   struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
#ifdef PCIDMA
	struct ni_gpct *counter = s->private;

	return ni_tio_cmdtest(counter, cmd);
#else
	return -ENOTSUPP;
#endif
}