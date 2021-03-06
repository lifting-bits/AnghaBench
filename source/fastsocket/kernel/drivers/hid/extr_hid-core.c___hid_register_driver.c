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
struct module {int dummy; } ;
struct TYPE_4__ {char const* mod_name; struct module* owner; int /*<<< orphan*/ * bus; int /*<<< orphan*/  name; } ;
struct hid_driver {TYPE_1__ driver; int /*<<< orphan*/  dyn_lock; int /*<<< orphan*/  dyn_list; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  driver_attr_new_id ; 
 int driver_create_file (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int driver_register (TYPE_1__*) ; 
 int /*<<< orphan*/  driver_unregister (TYPE_1__*) ; 
 int /*<<< orphan*/  hid_bus_type ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

int __hid_register_driver(struct hid_driver *hdrv, struct module *owner,
		const char *mod_name)
{
	int ret;

	hdrv->driver.name = hdrv->name;
	hdrv->driver.bus = &hid_bus_type;
	hdrv->driver.owner = owner;
	hdrv->driver.mod_name = mod_name;

	INIT_LIST_HEAD(&hdrv->dyn_list);
	spin_lock_init(&hdrv->dyn_lock);

	ret = driver_register(&hdrv->driver);
	if (ret)
		return ret;

	ret = driver_create_file(&hdrv->driver, &driver_attr_new_id);
	if (ret)
		driver_unregister(&hdrv->driver);

	return ret;
}