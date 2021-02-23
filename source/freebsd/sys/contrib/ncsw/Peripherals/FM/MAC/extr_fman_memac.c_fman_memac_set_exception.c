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
struct memac_regs {int /*<<< orphan*/  imask; } ;

/* Variables and functions */
 int /*<<< orphan*/  ioread32be (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iowrite32be (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void fman_memac_set_exception(struct memac_regs *regs, uint32_t val, bool enable)
{
    uint32_t tmp;

    tmp = ioread32be(&regs->imask);
    if (enable)
        tmp |= val;
    else
        tmp &= ~val;

    iowrite32be(tmp, &regs->imask);
}