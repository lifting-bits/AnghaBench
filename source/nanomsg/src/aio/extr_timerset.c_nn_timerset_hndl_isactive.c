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
struct nn_timerset_hndl {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int nn_list_item_isinlist (int /*<<< orphan*/ *) ; 

int nn_timerset_hndl_isactive (struct nn_timerset_hndl *self)
{
    return nn_list_item_isinlist (&self->list);
}