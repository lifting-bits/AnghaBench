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
struct clk_hw {int dummy; } ;
struct ccu_nkm {int /*<<< orphan*/  enable; int /*<<< orphan*/  common; } ;

/* Variables and functions */
 void ccu_gate_helper_disable (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct ccu_nkm* hw_to_ccu_nkm (struct clk_hw*) ; 

__attribute__((used)) static void ccu_nkm_disable(struct clk_hw *hw)
{
	struct ccu_nkm *nkm = hw_to_ccu_nkm(hw);

	return ccu_gate_helper_disable(&nkm->common, nkm->enable);
}