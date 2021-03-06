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
struct mpc85xx_mc_pdata {scalar_t__ mc_vbase; } ;
struct mem_ctl_info {struct mpc85xx_mc_pdata* pvt_info; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 scalar_t__ MPC85XX_MC_ECC_ERR_INJECT ; 
 scalar_t__ isdigit (char const) ; 
 int /*<<< orphan*/  out_be32 (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  simple_strtoul (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t mpc85xx_mc_inject_ctrl_store(struct mem_ctl_info *mci,
					    const char *data, size_t count)
{
	struct mpc85xx_mc_pdata *pdata = mci->pvt_info;
	if (isdigit(*data)) {
		out_be32(pdata->mc_vbase + MPC85XX_MC_ECC_ERR_INJECT,
			 simple_strtoul(data, NULL, 0));
		return count;
	}
	return 0;
}