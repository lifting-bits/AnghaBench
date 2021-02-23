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
struct ipmi_softc {int /*<<< orphan*/  ipmi_dev; } ;
struct ipmi_request {scalar_t__ ir_error; } ;

/* Variables and functions */
 scalar_t__ EIO ; 
 int /*<<< orphan*/  IPMI_LOCK (struct ipmi_softc*) ; 
 int /*<<< orphan*/  IPMI_UNLOCK (struct ipmi_softc*) ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*,int) ; 
 int hz ; 
 int /*<<< orphan*/  ipmi_complete_request (struct ipmi_softc*,struct ipmi_request*) ; 
 struct ipmi_request* ipmi_dequeue_request (struct ipmi_softc*) ; 
 int /*<<< orphan*/  kproc_exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pause (char*,int) ; 
 int ssif_polled_request (struct ipmi_softc*,struct ipmi_request*) ; 

__attribute__((used)) static void
ssif_loop(void *arg)
{
	struct ipmi_softc *sc = arg;
	struct ipmi_request *req;
	int i, ok;

	IPMI_LOCK(sc);
	while ((req = ipmi_dequeue_request(sc)) != NULL) {
		IPMI_UNLOCK(sc);
		ok = 0;
		for (i = 0; i < 5; i++) {
			ok = ssif_polled_request(sc, req);
			if (ok)
				break;

			/* Wait 60 ms between retries. */
			pause("retry", 60 * hz / 1000);
#ifdef SSIF_RETRY_DEBUG
			device_printf(sc->ipmi_dev,
			    "SSIF: Retrying request (%d)\n", i + 1);
#endif
		}
		if (ok)
			req->ir_error = 0;
		else
			req->ir_error = EIO;
		IPMI_LOCK(sc);
		ipmi_complete_request(sc, req);
		IPMI_UNLOCK(sc);

		/* Enforce 10ms between requests. */
		pause("delay", hz / 100);

		IPMI_LOCK(sc);
	}
	IPMI_UNLOCK(sc);
	kproc_exit(0);
}