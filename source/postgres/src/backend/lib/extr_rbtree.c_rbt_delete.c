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
typedef  int /*<<< orphan*/  RBTree ;
typedef  int /*<<< orphan*/  RBTNode ;

/* Variables and functions */
 int /*<<< orphan*/  rbt_delete_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void
rbt_delete(RBTree *rbt, RBTNode *node)
{
	rbt_delete_node(rbt, node);
}