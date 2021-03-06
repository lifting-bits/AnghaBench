#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {void (* call_on_tx ) (TYPE_1__*,void*,int) ;} ;
typedef  TYPE_1__ cx_chan_t ;

/* Variables and functions */

void cx_register_transmit (cx_chan_t *c,
	void (*func) (cx_chan_t *c, void *attachment, int len))
{
	c->call_on_tx = func;
}