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
 int contain_subplans_walker (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

bool
contain_subplans(Node *clause)
{
	return contain_subplans_walker(clause, NULL);
}