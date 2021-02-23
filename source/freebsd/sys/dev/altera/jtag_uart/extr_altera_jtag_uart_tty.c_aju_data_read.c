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
struct altera_jtag_uart_softc {int /*<<< orphan*/  ajus_mem_res; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALTERA_JTAG_UART_DATA_OFF ; 
 int /*<<< orphan*/  bus_read_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32toh (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint32_t
aju_data_read(struct altera_jtag_uart_softc *sc)
{

	return (le32toh(bus_read_4(sc->ajus_mem_res,
	    ALTERA_JTAG_UART_DATA_OFF)));
}