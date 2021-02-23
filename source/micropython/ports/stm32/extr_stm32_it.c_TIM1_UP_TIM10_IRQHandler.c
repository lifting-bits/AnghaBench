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
 int /*<<< orphan*/  TIM1_UP_TIM10_IRQn ; 
 int /*<<< orphan*/  timer_irq_handler (int) ; 

void TIM1_UP_TIM10_IRQHandler(void) {
    IRQ_ENTER(TIM1_UP_TIM10_IRQn);
    timer_irq_handler(1);
    timer_irq_handler(10);
    IRQ_EXIT(TIM1_UP_TIM10_IRQn);
}