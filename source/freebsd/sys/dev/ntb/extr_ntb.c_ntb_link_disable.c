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
struct ntb_child {scalar_t__ enabled; struct ntb_child* next; int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int NTB_LINK_DISABLE (int /*<<< orphan*/ ) ; 
 struct ntb_child* device_get_ivars (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 
 struct ntb_child** device_get_softc (int /*<<< orphan*/ ) ; 

int
ntb_link_disable(device_t ntb)
{
	struct ntb_child *nc = device_get_ivars(ntb);
	struct ntb_child **cpp = device_get_softc(device_get_parent(nc->dev));
	struct ntb_child *nc1;

	if (!nc->enabled)
		return (0);
	nc->enabled = 0;
	for (nc1 = *cpp; nc1 != NULL; nc1 = nc1->next) {
		if (nc1->enabled)
			return (0);
	}
	return (NTB_LINK_DISABLE(device_get_parent(ntb)));
}