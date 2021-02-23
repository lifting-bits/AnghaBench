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

/* Variables and functions */
 int DPORT_REG_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DPORT_REG_WRITE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RSA_INTERRUPT_REG ; 

__attribute__((used)) static inline void wait_op_complete(uint32_t op_reg)
{
    while(DPORT_REG_READ(RSA_INTERRUPT_REG) != 1)
       { }

    /* clear the interrupt */
    DPORT_REG_WRITE(RSA_INTERRUPT_REG, 1);
}