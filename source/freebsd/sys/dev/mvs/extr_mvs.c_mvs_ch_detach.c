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
struct mvs_channel {int pm_level; int /*<<< orphan*/  mtx; int /*<<< orphan*/  r_mem; int /*<<< orphan*/  unit; int /*<<< orphan*/  r_irq; int /*<<< orphan*/  ih; int /*<<< orphan*/  reset_timer; int /*<<< orphan*/  pm_timer; int /*<<< orphan*/  sim; int /*<<< orphan*/  path; scalar_t__ resetting; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  AC_LOST_DEVICE ; 
 int /*<<< orphan*/  ATA_IRQ_RID ; 
 int /*<<< orphan*/  SYS_RES_IRQ ; 
 int /*<<< orphan*/  SYS_RES_MEMORY ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  bus_release_resource (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_teardown_intr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  callout_drain (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cam_sim_free (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cam_sim_path (int /*<<< orphan*/ ) ; 
 struct mvs_channel* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mvs_ch_deinit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mvs_dmafini (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mvs_slotsfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xpt_async (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xpt_bus_deregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xpt_free_path (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xpt_release_simq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mvs_ch_detach(device_t dev)
{
	struct mvs_channel *ch = device_get_softc(dev);

	mtx_lock(&ch->mtx);
	xpt_async(AC_LOST_DEVICE, ch->path, NULL);
	/* Forget about reset. */
	if (ch->resetting) {
		ch->resetting = 0;
		xpt_release_simq(ch->sim, TRUE);
	}
	xpt_free_path(ch->path);
	xpt_bus_deregister(cam_sim_path(ch->sim));
	cam_sim_free(ch->sim, /*free_devq*/TRUE);
	mtx_unlock(&ch->mtx);

	if (ch->pm_level > 3)
		callout_drain(&ch->pm_timer);
	callout_drain(&ch->reset_timer);
	bus_teardown_intr(dev, ch->r_irq, ch->ih);
	bus_release_resource(dev, SYS_RES_IRQ, ATA_IRQ_RID, ch->r_irq);

	mvs_ch_deinit(dev);
	mvs_slotsfree(dev);
	mvs_dmafini(dev);

	bus_release_resource(dev, SYS_RES_MEMORY, ch->unit, ch->r_mem);
	mtx_destroy(&ch->mtx);
	return (0);
}