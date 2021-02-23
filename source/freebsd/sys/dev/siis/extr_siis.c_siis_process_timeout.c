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
struct siis_channel {int recovery; TYPE_1__* slot; int /*<<< orphan*/  numrslots; int /*<<< orphan*/  sim; int /*<<< orphan*/  recoverycmd; int /*<<< orphan*/  mtx; } ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {scalar_t__ state; } ;

/* Variables and functions */
 int /*<<< orphan*/  MA_OWNED ; 
 int /*<<< orphan*/  SIIS_ERR_TIMEOUT ; 
 int SIIS_MAX_SLOTS ; 
 scalar_t__ SIIS_SLOT_RUNNING ; 
 struct siis_channel* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_assert (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  siis_end_transaction (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xpt_freeze_simq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
siis_process_timeout(device_t dev)
{
	struct siis_channel *ch = device_get_softc(dev);
	int i;

	mtx_assert(&ch->mtx, MA_OWNED);
	if (!ch->recoverycmd && !ch->recovery) {
		xpt_freeze_simq(ch->sim, ch->numrslots);
		ch->recovery = 1;
	}
	/* Handle the rest of commands. */
	for (i = 0; i < SIIS_MAX_SLOTS; i++) {
		/* Do we have a running request on slot? */
		if (ch->slot[i].state < SIIS_SLOT_RUNNING)
			continue;
		siis_end_transaction(&ch->slot[i], SIIS_ERR_TIMEOUT);
	}
}