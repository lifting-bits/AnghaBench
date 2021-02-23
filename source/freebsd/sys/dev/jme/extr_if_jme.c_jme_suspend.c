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
struct jme_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  JME_LOCK (struct jme_softc*) ; 
 int /*<<< orphan*/  JME_UNLOCK (struct jme_softc*) ; 
 struct jme_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jme_setwol (struct jme_softc*) ; 
 int /*<<< orphan*/  jme_stop (struct jme_softc*) ; 

__attribute__((used)) static int
jme_suspend(device_t dev)
{
	struct jme_softc *sc;

	sc = device_get_softc(dev);

	JME_LOCK(sc);
	jme_stop(sc);
	jme_setwol(sc);
	JME_UNLOCK(sc);

	return (0);
}