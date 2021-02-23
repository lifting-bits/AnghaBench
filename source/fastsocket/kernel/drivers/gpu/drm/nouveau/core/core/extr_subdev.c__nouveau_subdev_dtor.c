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
struct nouveau_object {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nouveau_subdev_destroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nv_subdev (struct nouveau_object*) ; 

void
_nouveau_subdev_dtor(struct nouveau_object *object)
{
	nouveau_subdev_destroy(nv_subdev(object));
}