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
typedef  int /*<<< orphan*/  csr_config_t ;

/* Variables and functions */
 int /*<<< orphan*/  CSR_SYSCALL_CHECK ; 
 int __csrctl (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

int csr_check(csr_config_t mask)
{
	return __csrctl(CSR_SYSCALL_CHECK, &mask, sizeof(csr_config_t));
}