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
struct wpi_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WPI_LOCK (struct wpi_softc*) ; 
 int /*<<< orphan*/  WPI_UNLOCK (struct wpi_softc*) ; 
 int /*<<< orphan*/  wpi_stop_locked (struct wpi_softc*) ; 

__attribute__((used)) static void
wpi_stop(struct wpi_softc *sc)
{
	WPI_LOCK(sc);
	wpi_stop_locked(sc);
	WPI_UNLOCK(sc);
}