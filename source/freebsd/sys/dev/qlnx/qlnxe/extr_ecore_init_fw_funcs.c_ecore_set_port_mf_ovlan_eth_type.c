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
typedef  int /*<<< orphan*/  u32 ;
struct ecore_hwfn {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DORQ_REG_TAG1_ETHERTYPE_RT_OFFSET ; 
 int /*<<< orphan*/  STORE_RT_REG (struct ecore_hwfn*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void ecore_set_port_mf_ovlan_eth_type(struct ecore_hwfn *p_hwfn, u32 ethType)
{
	/* Update DORQ register */
	STORE_RT_REG(p_hwfn, DORQ_REG_TAG1_ETHERTYPE_RT_OFFSET, ethType);
}