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
struct uart_bas {int dummy; } ;
struct uart_softc {int sc_txdatasz; int* sc_txbuf; int sc_txbusy; int /*<<< orphan*/  sc_hwmtx; struct uart_bas sc_bas; } ;

/* Variables and functions */
 int CTRL_INTR_MASK ; 
 int CTRL_TX_IDLE_INT ; 
 int /*<<< orphan*/  UART_CTRL ; 
 int /*<<< orphan*/  UART_TSH ; 
 int /*<<< orphan*/  uart_barrier (struct uart_bas*) ; 
 int uart_getreg (struct uart_bas*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uart_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uart_setreg (struct uart_bas*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  uart_unlock (int /*<<< orphan*/ ) ; 

int
uart_mvebu_bus_transmit(struct uart_softc *sc)
{
	struct uart_bas *bas;
	int i, ctrl;

	bas = &sc->sc_bas;
	uart_lock(sc->sc_hwmtx);

	/* Turn off all interrupts during send */
	ctrl = uart_getreg(bas, UART_CTRL);
	uart_setreg(bas, UART_CTRL, ctrl & ~CTRL_INTR_MASK);
	uart_barrier(bas);

	for (i = 0; i < sc->sc_txdatasz; i++) {
		uart_setreg(bas, UART_TSH, sc->sc_txbuf[i] & 0xff);
		uart_barrier(bas);
	}

	/*
	 * Make sure that interrupt is generated
	 * when FIFO can get more data.
	 */
	uart_setreg(bas, UART_CTRL, ctrl | CTRL_TX_IDLE_INT);
	uart_barrier(bas);

	/* Mark busy */
	sc->sc_txbusy = 1;

	uart_unlock(sc->sc_hwmtx);
	return (0);
}