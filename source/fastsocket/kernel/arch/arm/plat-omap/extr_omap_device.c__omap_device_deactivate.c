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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct omap_device_pm_latency {scalar_t__ activate_lat; int deactivate_lat; int /*<<< orphan*/  (* deactivate_func ) (struct omap_device*) ;} ;
struct TYPE_2__ {int /*<<< orphan*/  id; int /*<<< orphan*/  name; } ;
struct omap_device {scalar_t__ pm_lat_level; scalar_t__ pm_lats_cnt; scalar_t__ dev_wakeup_lat; scalar_t__ _dev_wakeup_lat_limit; TYPE_1__ pdev; struct omap_device_pm_latency* pm_lats; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN (int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 
 int _read_32ksynct () ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  stub1 (struct omap_device*) ; 

__attribute__((used)) static int _omap_device_deactivate(struct omap_device *od, u8 ignore_lat)
{
	u32 a, b;

	pr_debug("omap_device: %s: deactivating\n", od->pdev.name);

	while (od->pm_lat_level < od->pm_lats_cnt) {
		struct omap_device_pm_latency *odpl;
		int deact_lat = 0;

		odpl = od->pm_lats + od->pm_lat_level;

		if (!ignore_lat &&
		    ((od->dev_wakeup_lat + odpl->activate_lat) >
		     od->_dev_wakeup_lat_limit))
			break;

		a = _read_32ksynct();

		/* XXX check return code */
		odpl->deactivate_func(od);

		b = _read_32ksynct();

		deact_lat = (b - a) >> 15; /* 32KiHz cycles to microseconds */

		pr_debug("omap_device: %s: pm_lat %d: deactivate: elapsed time "
			 "%d usec\n", od->pdev.name, od->pm_lat_level,
			 deact_lat);

		WARN(deact_lat > odpl->deactivate_lat, "omap_device: %s.%d: "
		     "deactivate step %d took longer than expected (%d > %d)\n",
		     od->pdev.name, od->pdev.id, od->pm_lat_level,
		     deact_lat, odpl->deactivate_lat);

		od->dev_wakeup_lat += odpl->activate_lat;

		od->pm_lat_level++;
	}

	return 0;
}