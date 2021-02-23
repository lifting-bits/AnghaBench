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
struct nv50_disp_base {int /*<<< orphan*/  ramht; } ;
struct nouveau_object {scalar_t__ parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  nouveau_ramht_remove (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
nvd0_disp_dmac_object_detach(struct nouveau_object *parent, int cookie)
{
	struct nv50_disp_base *base = (void *)parent->parent;
	nouveau_ramht_remove(base->ramht, cookie);
}