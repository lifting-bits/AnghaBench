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
struct hn_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HN_LOCK (struct hn_softc*) ; 
 int /*<<< orphan*/  HN_UNLOCK (struct hn_softc*) ; 
 int /*<<< orphan*/  hn_init_locked (struct hn_softc*) ; 

__attribute__((used)) static void
hn_init(void *xsc)
{
	struct hn_softc *sc = xsc;

	HN_LOCK(sc);
	hn_init_locked(sc);
	HN_UNLOCK(sc);
}