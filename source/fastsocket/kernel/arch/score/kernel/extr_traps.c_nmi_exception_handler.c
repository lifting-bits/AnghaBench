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
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  die (char*,struct pt_regs*) ; 
 int /*<<< orphan*/  die_if_kernel (char*,struct pt_regs*) ; 

void nmi_exception_handler(struct pt_regs *regs)
{
	die_if_kernel("nmi_exception_handler execution Exception", regs);
	die("NMI", regs);
}