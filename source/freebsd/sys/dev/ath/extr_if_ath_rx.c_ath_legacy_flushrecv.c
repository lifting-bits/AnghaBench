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
struct ath_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ath_rx_proc (struct ath_softc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
ath_legacy_flushrecv(struct ath_softc *sc)
{

	ath_rx_proc(sc, 0);
}