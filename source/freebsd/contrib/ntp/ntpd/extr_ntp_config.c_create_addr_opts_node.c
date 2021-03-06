#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  attr_val_fifo ;
typedef  int /*<<< orphan*/  address_node ;
struct TYPE_4__ {int /*<<< orphan*/ * options; int /*<<< orphan*/ * addr; } ;
typedef  TYPE_1__ addr_opts_node ;

/* Variables and functions */
 TYPE_1__* emalloc_zero (int) ; 

addr_opts_node *
create_addr_opts_node(
	address_node *	addr,
	attr_val_fifo *	options
	)
{
	addr_opts_node *my_node;

	my_node = emalloc_zero(sizeof(*my_node));
	my_node->addr = addr;
	my_node->options = options;

	return my_node;
}