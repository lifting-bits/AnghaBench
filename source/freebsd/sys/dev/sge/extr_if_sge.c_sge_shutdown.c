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
struct sge_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  SGE_LOCK (struct sge_softc*) ; 
 int /*<<< orphan*/  SGE_UNLOCK (struct sge_softc*) ; 
 struct sge_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sge_stop (struct sge_softc*) ; 

__attribute__((used)) static int
sge_shutdown(device_t dev)
{
	struct sge_softc *sc;

	sc = device_get_softc(dev);
	SGE_LOCK(sc);
	sge_stop(sc);
	SGE_UNLOCK(sc);
	return (0);
}