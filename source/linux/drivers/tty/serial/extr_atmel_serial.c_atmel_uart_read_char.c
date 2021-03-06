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
typedef  int /*<<< orphan*/  u8 ;
struct uart_port {scalar_t__ membase; } ;

/* Variables and functions */
 scalar_t__ ATMEL_US_RHR ; 
 int /*<<< orphan*/  __raw_readb (scalar_t__) ; 

__attribute__((used)) static inline u8 atmel_uart_read_char(struct uart_port *port)
{
	return __raw_readb(port->membase + ATMEL_US_RHR);
}