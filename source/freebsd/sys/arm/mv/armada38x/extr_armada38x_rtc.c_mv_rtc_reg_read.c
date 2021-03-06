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
typedef  int /*<<< orphan*/  uint32_t ;
struct mv_rtc_softc {int /*<<< orphan*/ * res; } ;
typedef  int /*<<< orphan*/  bus_size_t ;

/* Variables and functions */
 size_t RTC_RES ; 
 int /*<<< orphan*/  bus_read_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint32_t
mv_rtc_reg_read(struct mv_rtc_softc *sc, bus_size_t off)
{

	return (bus_read_4(sc->res[RTC_RES], off));
}