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
struct pp_hwmgr {int fan_ctrl_is_in_default_mode; void* tmin; void* fan_ctrl_default_mode; struct amdgpu_device* adev; } ;
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CG_FDO_CTRL2 ; 
 int /*<<< orphan*/  FDO_PWM_MODE ; 
 void* REG_GET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THM ; 
 int /*<<< orphan*/  TMIN ; 
 int /*<<< orphan*/  WREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmCG_FDO_CTRL2 ; 

int vega10_fan_ctrl_set_static_mode(struct pp_hwmgr *hwmgr, uint32_t mode)
{
	struct amdgpu_device *adev = hwmgr->adev;

	if (hwmgr->fan_ctrl_is_in_default_mode) {
		hwmgr->fan_ctrl_default_mode =
			REG_GET_FIELD(RREG32_SOC15(THM, 0, mmCG_FDO_CTRL2),
				CG_FDO_CTRL2, FDO_PWM_MODE);
		hwmgr->tmin =
			REG_GET_FIELD(RREG32_SOC15(THM, 0, mmCG_FDO_CTRL2),
				CG_FDO_CTRL2, TMIN);
		hwmgr->fan_ctrl_is_in_default_mode = false;
	}

	WREG32_SOC15(THM, 0, mmCG_FDO_CTRL2,
			REG_SET_FIELD(RREG32_SOC15(THM, 0, mmCG_FDO_CTRL2),
				CG_FDO_CTRL2, TMIN, 0));
	WREG32_SOC15(THM, 0, mmCG_FDO_CTRL2,
			REG_SET_FIELD(RREG32_SOC15(THM, 0, mmCG_FDO_CTRL2),
				CG_FDO_CTRL2, FDO_PWM_MODE, mode));

	return 0;
}