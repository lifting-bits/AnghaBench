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
typedef  int uint32_t ;
struct TYPE_4__ {int CR2; int SR1; } ;
typedef  scalar_t__ ITStatus ;
typedef  TYPE_1__ I2C_TypeDef ;

/* Variables and functions */
 int FLAG_MASK ; 
 int /*<<< orphan*/  IS_I2C_ALL_PERIPH (TYPE_1__*) ; 
 int /*<<< orphan*/  IS_I2C_GET_IT (int) ; 
 int ITEN_MASK ; 
 scalar_t__ RESET ; 
 scalar_t__ SET ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t enablestatus = 0;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_GET_IT(I2C_IT));

  /* Check if the interrupt source is enabled or not */
  enablestatus = (uint32_t)(((I2C_IT & ITEN_MASK) >> 16) & (I2Cx->CR2)) ;
  
  /* Get bit[23:0] of the flag */
  I2C_IT &= FLAG_MASK;

  /* Check the status of the specified I2C flag */
  if (((I2Cx->SR1 & I2C_IT) != (uint32_t)RESET) && enablestatus)
  {
    /* I2C_IT is set */
    bitstatus = SET;
  }
  else
  {
    /* I2C_IT is reset */
    bitstatus = RESET;
  }
  /* Return the I2C_IT status */
  return  bitstatus;
}