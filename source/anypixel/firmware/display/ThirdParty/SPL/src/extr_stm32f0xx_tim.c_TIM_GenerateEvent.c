#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_4__ {int /*<<< orphan*/  EGR; } ;
typedef  TYPE_1__ TIM_TypeDef ;

/* Variables and functions */
 int /*<<< orphan*/  IS_TIM_ALL_PERIPH (TYPE_1__*) ; 
 int /*<<< orphan*/  IS_TIM_EVENT_SOURCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource)
{ 
  /* Check the parameters */
  assert_param(IS_TIM_ALL_PERIPH(TIMx));
  assert_param(IS_TIM_EVENT_SOURCE(TIM_EventSource)); 
  /* Set the event sources */
  TIMx->EGR = TIM_EventSource;
}