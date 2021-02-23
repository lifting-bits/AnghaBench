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
struct addrtree {struct addrnode* root; } ;
struct addrnode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  lru_pop (struct addrtree*,struct addrnode*) ; 
 int /*<<< orphan*/  lru_push (struct addrtree*,struct addrnode*) ; 

__attribute__((used)) static void
lru_update(struct addrtree *tree, struct addrnode *node)
{
	if (tree->root == node) return;
	lru_pop(tree, node);
	lru_push(tree, node);
}