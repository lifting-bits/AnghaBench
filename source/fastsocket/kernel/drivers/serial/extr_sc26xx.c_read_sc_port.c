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
typedef  scalar_t__ u8 ;
struct uart_port {int line; scalar_t__ membase; } ;

/* Variables and functions */
 scalar_t__ readb (scalar_t__) ; 

__attribute__((used)) static inline u8 read_sc_port(struct uart_port *p, u8 reg)
{
	return readb(p->membase + p->line * 0x20 + reg);
}