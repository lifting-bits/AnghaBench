#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  eppData0; } ;
struct parport_ip32_private {TYPE_2__ regs; } ;
struct parport {TYPE_1__* physport; } ;
struct TYPE_3__ {struct parport_ip32_private* private_data; } ;

/* Variables and functions */
 size_t parport_ip32_epp_read (int /*<<< orphan*/ ,struct parport*,void*,size_t,int) ; 

__attribute__((used)) static size_t parport_ip32_epp_read_data(struct parport *p, void *buf,
					 size_t len, int flags)
{
	struct parport_ip32_private * const priv = p->physport->private_data;
	return parport_ip32_epp_read(priv->regs.eppData0, p, buf, len, flags);
}