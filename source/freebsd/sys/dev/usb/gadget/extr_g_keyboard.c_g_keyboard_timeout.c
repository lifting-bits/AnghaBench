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
struct g_keyboard_softc {int /*<<< orphan*/ * sc_xfer; scalar_t__* sc_pattern; int /*<<< orphan*/  sc_pattern_len; int /*<<< orphan*/  sc_mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTFN (int,char*,int /*<<< orphan*/ ) ; 
 size_t G_KEYBOARD_INTR_DT ; 
 int G_KEYBOARD_MAX_STRLEN ; 
 int /*<<< orphan*/  g_keyboard_key_press_pattern ; 
 int /*<<< orphan*/  g_keyboard_mode ; 
 int /*<<< orphan*/  g_keyboard_timeout_reset (struct g_keyboard_softc*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strlen (scalar_t__*) ; 
 int /*<<< orphan*/  usbd_transfer_start (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
g_keyboard_timeout(void *arg)
{
	struct g_keyboard_softc *sc = arg;

	sc->sc_mode = g_keyboard_mode;

	memcpy(sc->sc_pattern, g_keyboard_key_press_pattern, sizeof(sc->sc_pattern));

	sc->sc_pattern[G_KEYBOARD_MAX_STRLEN - 1] = 0;

	sc->sc_pattern_len = strlen(sc->sc_pattern);

	DPRINTFN(11, "Timeout %p\n", sc->sc_xfer[G_KEYBOARD_INTR_DT]);

	usbd_transfer_start(sc->sc_xfer[G_KEYBOARD_INTR_DT]);

	g_keyboard_timeout_reset(sc);
}