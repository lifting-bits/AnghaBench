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
struct nn_list_item {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nn_assert (int) ; 
 int /*<<< orphan*/  nn_list_item_isinlist (struct nn_list_item*) ; 

void nn_list_item_term (struct nn_list_item *self)
{
    nn_assert (!nn_list_item_isinlist (self));
}