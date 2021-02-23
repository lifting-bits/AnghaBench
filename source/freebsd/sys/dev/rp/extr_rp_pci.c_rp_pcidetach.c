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
typedef  int /*<<< orphan*/  device_t ;
typedef  int /*<<< orphan*/  CONTROLLER_t ;

/* Variables and functions */
 int /*<<< orphan*/ * device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rp_pcireleaseresource (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
rp_pcidetach(device_t dev)
{
	CONTROLLER_t	*ctlp;

	ctlp = device_get_softc(dev);
	rp_pcireleaseresource(ctlp);

	return (0);
}