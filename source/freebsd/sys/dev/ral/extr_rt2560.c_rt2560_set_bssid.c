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
typedef  int uint8_t ;
typedef  int uint32_t ;
struct rt2560_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTF (struct rt2560_softc*,char*,int const*,char*) ; 
 int /*<<< orphan*/  RAL_WRITE (struct rt2560_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RT2560_CSR5 ; 
 int /*<<< orphan*/  RT2560_CSR6 ; 

__attribute__((used)) static void
rt2560_set_bssid(struct rt2560_softc *sc, const uint8_t *bssid)
{
	uint32_t tmp;

	tmp = bssid[0] | bssid[1] << 8 | bssid[2] << 16 | bssid[3] << 24;
	RAL_WRITE(sc, RT2560_CSR5, tmp);

	tmp = bssid[4] | bssid[5] << 8;
	RAL_WRITE(sc, RT2560_CSR6, tmp);

	DPRINTF(sc, "setting BSSID to %6D\n", bssid, ":");
}