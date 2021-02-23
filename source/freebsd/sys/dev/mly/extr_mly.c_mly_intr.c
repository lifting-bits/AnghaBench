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
struct mly_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLY_LOCK (struct mly_softc*) ; 
 int /*<<< orphan*/  MLY_UNLOCK (struct mly_softc*) ; 
 int /*<<< orphan*/  debug_called (int) ; 
 int /*<<< orphan*/  mly_done (struct mly_softc*) ; 

__attribute__((used)) static void
mly_intr(void *arg)
{
    struct mly_softc	*sc = (struct mly_softc *)arg;

    debug_called(2);

    MLY_LOCK(sc);
    mly_done(sc);
    MLY_UNLOCK(sc);
}