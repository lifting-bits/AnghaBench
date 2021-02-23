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
typedef  int /*<<< orphan*/  ulong ;

/* Variables and functions */
 scalar_t__ CCM_UPCTL ; 
 scalar_t__ CRM_BASE ; 
 int /*<<< orphan*/  __raw_readl (scalar_t__) ; 
 unsigned long mxc_decode_pll (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static unsigned long get_rate_upll(void)
{
	ulong mpctl = __raw_readl(CRM_BASE + CCM_UPCTL);

	return mxc_decode_pll(mpctl, 24000000);
}