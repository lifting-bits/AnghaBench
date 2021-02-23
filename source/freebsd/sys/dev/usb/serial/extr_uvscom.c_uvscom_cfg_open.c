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
struct uvscom_softc {int dummy; } ;
struct ucom_softc {struct uvscom_softc* sc_parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (char*,struct uvscom_softc*) ; 
 int /*<<< orphan*/  uvscom_cfg_read_status (struct uvscom_softc*) ; 

__attribute__((used)) static void
uvscom_cfg_open(struct ucom_softc *ucom)
{
	struct uvscom_softc *sc = ucom->sc_parent;

	DPRINTF("sc = %p\n", sc);

	uvscom_cfg_read_status(sc);
}