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
struct thread {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/ * tc_poll_pps; } ;
struct dmtpps_softc {TYPE_1__ tc; } ;
struct cdev {struct dmtpps_softc* si_drv1; } ;

/* Variables and functions */
 int /*<<< orphan*/  dmtpps_set_hw_capture (struct dmtpps_softc*,int) ; 

__attribute__((used)) static	int
dmtpps_close(struct cdev *dev, int flags, int fmt, 
    struct thread *td)
{
	struct dmtpps_softc *sc;

	sc = dev->si_drv1;

	/*
	 * Stop polling and disable capture on last close.  Use the force-off
	 * flag to override the configured mode and turn off the hardware.
	 */
	sc->tc.tc_poll_pps = NULL;
	dmtpps_set_hw_capture(sc, true);

	return 0;
}