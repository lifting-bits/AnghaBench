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
struct ipmi_softc {int /*<<< orphan*/  ipmi_dev; int /*<<< orphan*/  ipmi_kthread; } ;

/* Variables and functions */
 int /*<<< orphan*/  device_get_nameunit (int /*<<< orphan*/ ) ; 
 int kproc_create (int /*<<< orphan*/ ,struct ipmi_softc*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssif_loop ; 

__attribute__((used)) static int
ssif_startup(struct ipmi_softc *sc)
{

	return (kproc_create(ssif_loop, sc, &sc->ipmi_kthread, 0, 0,
	    "%s: ssif", device_get_nameunit(sc->ipmi_dev)));
}