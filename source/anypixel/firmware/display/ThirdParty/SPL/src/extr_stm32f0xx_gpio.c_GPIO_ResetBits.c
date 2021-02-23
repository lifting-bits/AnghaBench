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
struct TYPE_4__ {int /*<<< orphan*/  BRR; } ;
typedef  TYPE_1__ GPIO_TypeDef ;

/* Variables and functions */
 int /*<<< orphan*/  IS_GPIO_ALL_PERIPH (TYPE_1__*) ; 
 int /*<<< orphan*/  IS_GPIO_PIN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  GPIOx->BRR = GPIO_Pin;
}