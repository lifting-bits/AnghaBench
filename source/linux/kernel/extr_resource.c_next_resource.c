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
struct resource {struct resource* sibling; struct resource* parent; struct resource* child; } ;

/* Variables and functions */

__attribute__((used)) static struct resource *next_resource(struct resource *p, bool sibling_only)
{
	/* Caller wants to traverse through siblings only */
	if (sibling_only)
		return p->sibling;

	if (p->child)
		return p->child;
	while (!p->sibling && p->parent)
		p = p->parent;
	return p->sibling;
}