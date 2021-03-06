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
struct uart_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT_SET (struct uart_port*,int /*<<< orphan*/ ,int) ; 
 int RxInt ; 
 int RxTimeoutInt ; 
 int /*<<< orphan*/  UART_R_INTEN ; 

__attribute__((used)) static void lh7a40xuart_stop_rx (struct uart_port* port)
{
	BIT_SET (port, UART_R_INTEN, RxTimeoutInt | RxInt);
}