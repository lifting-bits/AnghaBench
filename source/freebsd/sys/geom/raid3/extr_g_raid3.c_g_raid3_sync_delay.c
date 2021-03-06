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
struct g_raid3_softc {int /*<<< orphan*/  sc_sync_delayed; } ;
struct bio {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  G_RAID3_LOGREQ (int,struct bio*,char*) ; 
 int /*<<< orphan*/  bioq_insert_tail (int /*<<< orphan*/ *,struct bio*) ; 

__attribute__((used)) static void
g_raid3_sync_delay(struct g_raid3_softc *sc, struct bio *bp)
{

	G_RAID3_LOGREQ(2, bp, "Delaying synchronization request.");
	bioq_insert_tail(&sc->sc_sync_delayed, bp);
}