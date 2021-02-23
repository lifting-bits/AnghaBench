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
typedef  int u_int ;
struct ti_aintc_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTC_MIR_CLEAR (int) ; 
 int /*<<< orphan*/  aintc_write_4 (struct ti_aintc_softc*,int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static inline void
ti_aintc_irq_unmask(struct ti_aintc_softc *sc, u_int irq)
{

	aintc_write_4(sc, INTC_MIR_CLEAR(irq >> 5), (1UL << (irq & 0x1F)));
}