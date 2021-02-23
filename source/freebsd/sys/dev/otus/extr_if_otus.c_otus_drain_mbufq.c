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
struct otus_softc {int /*<<< orphan*/  sc_snd; } ;
struct TYPE_2__ {int /*<<< orphan*/ * rcvif; } ;
struct mbuf {TYPE_1__ m_pkthdr; } ;
struct ieee80211_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OTUS_LOCK_ASSERT (struct otus_softc*) ; 
 int /*<<< orphan*/  ieee80211_free_node (struct ieee80211_node*) ; 
 int /*<<< orphan*/  m_freem (struct mbuf*) ; 
 struct mbuf* mbufq_dequeue (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
otus_drain_mbufq(struct otus_softc *sc)
{
	struct mbuf *m;
	struct ieee80211_node *ni;

	OTUS_LOCK_ASSERT(sc);
	while ((m = mbufq_dequeue(&sc->sc_snd)) != NULL) {
		ni = (struct ieee80211_node *) m->m_pkthdr.rcvif;
		m->m_pkthdr.rcvif = NULL;
		ieee80211_free_node(ni);
		m_freem(m);
	}
}