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
typedef  int uint32_t ;
struct TYPE_2__ {int chip_id; } ;
struct bhnd_pmu_query {TYPE_1__ cid; } ;

/* Variables and functions */
 int BHND_CHIPID_BCM4319 ; 
 int BHND_CHIPID_BCM43234 ; 
 int BHND_CHIPID_BCM43235 ; 
 int BHND_CHIPID_BCM43236 ; 
 int BHND_CHIPID_BCM43237 ; 
 int BHND_CHIPID_BCM43238 ; 
 int BHND_CHIPID_BCM4329 ; 
 int BHND_CHIPID_BCM4330 ; 
 int BHND_CHIPID_BCM4336 ; 
#define  BHND_CHIPID_BCM4706 131 
#define  BHND_CHIPID_BCM4749 130 
 int BHND_CHIPID_BCM5354 ; 
#define  BHND_CHIPID_BCM5356 129 
#define  BHND_CHIPID_BCM5357 128 
 int BHND_CHIPID_BCM53572 ; 
 int /*<<< orphan*/  BHND_PMU4706_MAINPLL_PLL0 ; 
 int /*<<< orphan*/  BHND_PMU4716_MAINPLL_PLL0 ; 
 int /*<<< orphan*/  BHND_PMU5356_MAINPLL_PLL0 ; 
 int /*<<< orphan*/  BHND_PMU5357_MAINPLL_PLL0 ; 
 int /*<<< orphan*/  BHND_PMU5_MAINPLL_CPU ; 
 int /*<<< orphan*/  BHND_PMU6_MAINPLL_CPU ; 
 int BHND_PMU_REV (struct bhnd_pmu_query*) ; 
 int bhnd_pmu5_clock (struct bhnd_pmu_query*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bhnd_pmu6_4706_clock (struct bhnd_pmu_query*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int bhnd_pmu_si_clock (struct bhnd_pmu_query*) ; 

uint32_t 
bhnd_pmu_cpu_clock(struct bhnd_pmu_query *sc)
{
	/* 5354 chip uses a non programmable PLL of frequency 240MHz */
	if (sc->cid.chip_id == BHND_CHIPID_BCM5354)
		return (240 * 1000 * 1000); /* 240MHz */

	if (sc->cid.chip_id == BHND_CHIPID_BCM53572)
		return (300000000);

	if (BHND_PMU_REV(sc) >= 5 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM4329 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM4319 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM43234 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM43235 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM43236 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM43237 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM43238 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM4336 &&
	    sc->cid.chip_id != BHND_CHIPID_BCM4330)
	{
		switch (sc->cid.chip_id) {
		case BHND_CHIPID_BCM5356:
			return (bhnd_pmu5_clock(sc, BHND_PMU5356_MAINPLL_PLL0,
			    BHND_PMU5_MAINPLL_CPU));

		case BHND_CHIPID_BCM5357:
		case BHND_CHIPID_BCM4749:
			return (bhnd_pmu5_clock(sc, BHND_PMU5357_MAINPLL_PLL0,
			    BHND_PMU5_MAINPLL_CPU));

		case BHND_CHIPID_BCM4706:
			return (bhnd_pmu6_4706_clock(sc,
			    BHND_PMU4706_MAINPLL_PLL0, BHND_PMU6_MAINPLL_CPU));

		default:
			return (bhnd_pmu5_clock(sc, BHND_PMU4716_MAINPLL_PLL0,
			    BHND_PMU5_MAINPLL_CPU));
		}
	} else {
		return (bhnd_pmu_si_clock(sc));
	}
}