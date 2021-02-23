#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct nouveau_object {int dummy; } ;
struct TYPE_2__ {scalar_t__ mmio; } ;
struct nouveau_device {TYPE_1__ base; int /*<<< orphan*/  head; } ;

/* Variables and functions */
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nouveau_subdev_destroy (TYPE_1__*) ; 
 int /*<<< orphan*/  nv_devices_mutex ; 

__attribute__((used)) static void
nouveau_device_dtor(struct nouveau_object *object)
{
	struct nouveau_device *device = (void *)object;

	mutex_lock(&nv_devices_mutex);
	list_del(&device->head);
	mutex_unlock(&nv_devices_mutex);

	if (device->base.mmio)
		iounmap(device->base.mmio);

	nouveau_subdev_destroy(&device->base);
}