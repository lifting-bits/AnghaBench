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
struct nn_ins_item {int /*<<< orphan*/  item; struct nn_ep* ep; } ;
struct nn_ep {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nn_list_item_init (int /*<<< orphan*/ *) ; 

void nn_ins_item_init (struct nn_ins_item *self, struct nn_ep *ep)
{
    self->ep = ep;
    nn_list_item_init (&self->item);
}