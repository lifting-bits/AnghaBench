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
struct visor_device {int /*<<< orphan*/  visorchannel; } ;

/* Variables and functions */
 int visorchannel_write (int /*<<< orphan*/ ,unsigned long,void*,unsigned long) ; 

int visorbus_write_channel(struct visor_device *dev, unsigned long offset,
			   void *src, unsigned long nbytes)
{
	return visorchannel_write(dev->visorchannel, offset, src, nbytes);
}