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
struct cam_sim {int dummy; } ;
struct ISCI_CONTROLLER {int dummy; } ;

/* Variables and functions */
 scalar_t__ cam_sim_softc (struct cam_sim*) ; 
 int /*<<< orphan*/  isci_interrupt_poll_handler (struct ISCI_CONTROLLER*) ; 

void isci_poll(struct cam_sim *sim)
{
	struct ISCI_CONTROLLER *controller =
	    (struct ISCI_CONTROLLER *)cam_sim_softc(sim);

	isci_interrupt_poll_handler(controller);
}