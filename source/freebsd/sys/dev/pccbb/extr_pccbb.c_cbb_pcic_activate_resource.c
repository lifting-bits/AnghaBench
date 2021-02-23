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
struct resource {int dummy; } ;
struct cbb_softc {int /*<<< orphan*/ * exca; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  cbb_activate_window (int /*<<< orphan*/ ,int) ; 
 struct cbb_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int exca_activate_resource (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,struct resource*) ; 

__attribute__((used)) static int
cbb_pcic_activate_resource(device_t brdev, device_t child, int type, int rid,
    struct resource *res)
{
	struct cbb_softc *sc = device_get_softc(brdev);
	int error;

	error = exca_activate_resource(&sc->exca[0], child, type, rid, res);
	if (error == 0)
		cbb_activate_window(brdev, type);
	return (error);
}