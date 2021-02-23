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
struct zyd_softc {int dummy; } ;
struct zyd_rf {struct zyd_softc* rf_sc; } ;

/* Variables and functions */
 int /*<<< orphan*/  ZYD_CR11 ; 
 int /*<<< orphan*/  ZYD_CR251 ; 
 int /*<<< orphan*/  zyd_write16_m (struct zyd_softc*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
zyd_al7230B_switch_radio(struct zyd_rf *rf, int on)
{
	int error;
	struct zyd_softc *sc = rf->rf_sc;

	zyd_write16_m(sc, ZYD_CR11,  on ? 0x00 : 0x04);
	zyd_write16_m(sc, ZYD_CR251, on ? 0x3f : 0x2f);
fail:
	return (error);
}