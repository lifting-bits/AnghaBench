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
struct vtcon_softc {int dummy; } ;

/* Variables and functions */
 int vtcon_ctrl_event_populate (struct vtcon_softc*) ; 

__attribute__((used)) static int
vtcon_ctrl_init(struct vtcon_softc *sc)
{
	int error;

	error = vtcon_ctrl_event_populate(sc);

	return (error);
}