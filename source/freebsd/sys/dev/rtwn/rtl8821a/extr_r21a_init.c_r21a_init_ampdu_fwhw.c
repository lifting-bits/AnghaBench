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
struct rtwn_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  R92C_FAST_EDCA_CTRL ; 
 int /*<<< orphan*/  R92C_FWHW_TXQ_CTRL ; 
 int /*<<< orphan*/  R92C_FWHW_TXQ_CTRL_AMPDU_RTY_NEW ; 
 int /*<<< orphan*/  rtwn_write_1 (struct rtwn_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtwn_write_4 (struct rtwn_softc*,int /*<<< orphan*/ ,int) ; 

void
r21a_init_ampdu_fwhw(struct rtwn_softc *sc)
{
	rtwn_write_1(sc, R92C_FWHW_TXQ_CTRL,
	    R92C_FWHW_TXQ_CTRL_AMPDU_RTY_NEW);
	rtwn_write_4(sc, R92C_FAST_EDCA_CTRL, 0x03087777);
}