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
struct pp_hwmgr {int /*<<< orphan*/ * device; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  cgs_write_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmMP0PUB_IND_DATA_0 ; 
 int smu8_set_smc_sram_address (struct pp_hwmgr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int smu8_write_smc_sram_dword(struct pp_hwmgr *hwmgr,
		uint32_t smc_address, uint32_t value, uint32_t limit)
{
	int result;

	if (hwmgr == NULL || hwmgr->device == NULL)
		return -EINVAL;

	result = smu8_set_smc_sram_address(hwmgr, smc_address, limit);
	if (!result)
		cgs_write_register(hwmgr->device, mmMP0PUB_IND_DATA_0, value);

	return result;
}