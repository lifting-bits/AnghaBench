#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct s5p_mfc_dev {TYPE_1__* mfc_regs; } ;
struct TYPE_2__ {int /*<<< orphan*/  d_min_num_dpb; } ;

/* Variables and functions */
 int readl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int s5p_mfc_get_dpb_count_v6(struct s5p_mfc_dev *dev)
{
	return readl(dev->mfc_regs->d_min_num_dpb);
}