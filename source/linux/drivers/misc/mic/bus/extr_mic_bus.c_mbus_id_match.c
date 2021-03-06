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
struct mbus_device_id {scalar_t__ device; scalar_t__ vendor; } ;
struct TYPE_2__ {scalar_t__ device; scalar_t__ vendor; } ;
struct mbus_device {TYPE_1__ id; } ;

/* Variables and functions */
 scalar_t__ MBUS_DEV_ANY_ID ; 

__attribute__((used)) static inline int mbus_id_match(const struct mbus_device *dev,
				const struct mbus_device_id *id)
{
	if (id->device != dev->id.device && id->device != MBUS_DEV_ANY_ID)
		return 0;

	return id->vendor == MBUS_DEV_ANY_ID || id->vendor == dev->id.vendor;
}