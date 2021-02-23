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
struct i40e_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  I40E_VFGEN_RSTAT ; 
 int /*<<< orphan*/  I40E_VFINT_DYN_CTL01 ; 
 int I40E_VFINT_DYN_CTL01_INTENA_MASK ; 
 int I40E_VFINT_DYN_CTL01_ITR_INDX_MASK ; 
 int /*<<< orphan*/  I40E_VFINT_ICR0_ENA1 ; 
 int I40E_VFINT_ICR0_ENA1_ADMINQ_MASK ; 
 int /*<<< orphan*/  rd32 (struct i40e_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wr32 (struct i40e_hw*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
iavf_enable_adminq_irq(struct i40e_hw *hw)
{
	wr32(hw, I40E_VFINT_DYN_CTL01,
	    I40E_VFINT_DYN_CTL01_INTENA_MASK |
	    I40E_VFINT_DYN_CTL01_ITR_INDX_MASK);
	wr32(hw, I40E_VFINT_ICR0_ENA1, I40E_VFINT_ICR0_ENA1_ADMINQ_MASK);
	/* flush */
	rd32(hw, I40E_VFGEN_RSTAT);
}