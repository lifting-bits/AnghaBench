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
struct comedi_subdevice {struct comedi_async* async; } ;
struct comedi_device {unsigned int n_subdevices; struct comedi_subdevice* subdevices; } ;
struct comedi_async {int dummy; } ;

/* Variables and functions */
 unsigned int comedi_buf_read_n_available (struct comedi_async*) ; 

int comedi_get_buffer_contents(void *d, unsigned int subdevice)
{
	struct comedi_device *dev = (struct comedi_device *)d;
	struct comedi_subdevice *s = dev->subdevices + subdevice;
	struct comedi_async *async;
	unsigned int num_bytes;

	if (subdevice >= dev->n_subdevices)
		return -1;
	async = s->async;
	if (async == NULL)
		return 0;
	num_bytes = comedi_buf_read_n_available(s->async);
	return num_bytes;
}