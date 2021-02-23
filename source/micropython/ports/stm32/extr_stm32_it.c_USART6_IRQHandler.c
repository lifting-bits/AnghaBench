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

/* Variables and functions */
 int /*<<< orphan*/  IRQ_ENTER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQ_EXIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  USART6_IRQn ; 
 int /*<<< orphan*/  uart_irq_handler (int) ; 

void USART6_IRQHandler(void) {
    IRQ_ENTER(USART6_IRQn);
    uart_irq_handler(6);
    IRQ_EXIT(USART6_IRQn);
}