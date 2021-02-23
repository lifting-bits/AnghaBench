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
struct nouveau_gpio {int /*<<< orphan*/  base; int /*<<< orphan*/  events; } ;

/* Variables and functions */
 int /*<<< orphan*/  nouveau_event_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nouveau_subdev_destroy (int /*<<< orphan*/ *) ; 

void
_nouveau_gpio_dtor(struct nouveau_object *object)
{
	struct nouveau_gpio *gpio = (void *)object;
	nouveau_event_destroy(&gpio->events);
	nouveau_subdev_destroy(&gpio->base);
}