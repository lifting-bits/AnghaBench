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
struct g_raid3_softc {int dummy; } ;
struct g_provider {int /*<<< orphan*/  name; TYPE_1__* geom; } ;
struct g_consumer {int acw; int /*<<< orphan*/  ace; int /*<<< orphan*/  acr; struct g_provider* provider; int /*<<< orphan*/ * private; } ;
struct TYPE_2__ {int flags; } ;

/* Variables and functions */
 int G_GEOM_WITHER ; 
 int /*<<< orphan*/  G_RAID3_DEBUG (int,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  M_WAITOK ; 
 int /*<<< orphan*/  g_access (struct g_consumer*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_destroy_consumer (struct g_consumer*) ; 
 int /*<<< orphan*/  g_detach (struct g_consumer*) ; 
 int /*<<< orphan*/  g_post_event (int /*<<< orphan*/ ,struct g_consumer*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_raid3_destroy_consumer ; 
 scalar_t__ g_raid3_is_busy (struct g_raid3_softc*,struct g_consumer*) ; 
 int /*<<< orphan*/  g_topology_assert () ; 

__attribute__((used)) static void
g_raid3_kill_consumer(struct g_raid3_softc *sc, struct g_consumer *cp)
{
	struct g_provider *pp;
	int retaste_wait;

	g_topology_assert();

	cp->private = NULL;
	if (g_raid3_is_busy(sc, cp))
		return;
	G_RAID3_DEBUG(2, "Consumer %s destroyed.", cp->provider->name);
	pp = cp->provider;
	retaste_wait = 0;
	if (cp->acw == 1) {
		if ((pp->geom->flags & G_GEOM_WITHER) == 0)
			retaste_wait = 1;
	}
	G_RAID3_DEBUG(2, "Access %s r%dw%de%d = %d", pp->name, -cp->acr,
	    -cp->acw, -cp->ace, 0);
	if (cp->acr > 0 || cp->acw > 0 || cp->ace > 0)
		g_access(cp, -cp->acr, -cp->acw, -cp->ace);
	if (retaste_wait) {
		/*
		 * After retaste event was send (inside g_access()), we can send
		 * event to detach and destroy consumer.
		 * A class, which has consumer to the given provider connected
		 * will not receive retaste event for the provider.
		 * This is the way how I ignore retaste events when I close
		 * consumers opened for write: I detach and destroy consumer
		 * after retaste event is sent.
		 */
		g_post_event(g_raid3_destroy_consumer, cp, M_WAITOK, NULL);
		return;
	}
	G_RAID3_DEBUG(1, "Consumer %s destroyed.", pp->name);
	g_detach(cp);
	g_destroy_consumer(cp);
}