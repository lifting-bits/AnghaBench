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
typedef  int /*<<< orphan*/  Node ;

/* Variables and functions */
 int contain_context_dependent_node_walker (int /*<<< orphan*/ *,int*) ; 

__attribute__((used)) static bool
contain_context_dependent_node(Node *clause)
{
	int			flags = 0;

	return contain_context_dependent_node_walker(clause, &flags);
}