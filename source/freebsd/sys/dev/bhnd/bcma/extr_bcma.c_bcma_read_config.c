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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
typedef  scalar_t__ u_int ;
struct bhnd_resource {int /*<<< orphan*/  res; } ;
struct bcma_devinfo {struct bhnd_resource* res_agent; } ;
typedef  scalar_t__ device_t ;
typedef  scalar_t__ bus_size_t ;

/* Variables and functions */
 int EFAULT ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  bhnd_bus_read_1 (struct bhnd_resource*,scalar_t__) ; 
 int /*<<< orphan*/  bhnd_bus_read_2 (struct bhnd_resource*,scalar_t__) ; 
 int /*<<< orphan*/  bhnd_bus_read_4 (struct bhnd_resource*,scalar_t__) ; 
 struct bcma_devinfo* device_get_ivars (scalar_t__) ; 
 scalar_t__ device_get_parent (scalar_t__) ; 
 scalar_t__ rman_get_size (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
bcma_read_config(device_t dev, device_t child, bus_size_t offset, void *value,
    u_int width)
{
	struct bcma_devinfo	*dinfo;
	struct bhnd_resource	*r;

	/* Must be a directly attached child core */
	if (device_get_parent(child) != dev)
		return (EINVAL);

	/* Fetch the agent registers */
	dinfo = device_get_ivars(child);
	if ((r = dinfo->res_agent) == NULL)
		return (ENODEV);

	/* Verify bounds */
	if (offset > rman_get_size(r->res))
		return (EFAULT);

	if (rman_get_size(r->res) - offset < width)
		return (EFAULT);

	switch (width) {
	case 1:
		*((uint8_t *)value) = bhnd_bus_read_1(r, offset);
		return (0);
	case 2:
		*((uint16_t *)value) = bhnd_bus_read_2(r, offset);
		return (0);
	case 4:
		*((uint32_t *)value) = bhnd_bus_read_4(r, offset);
		return (0);
	default:
		return (EINVAL);
	}
}