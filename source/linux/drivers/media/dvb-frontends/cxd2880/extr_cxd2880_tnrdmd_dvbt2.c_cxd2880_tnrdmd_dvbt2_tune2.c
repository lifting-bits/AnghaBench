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
typedef  int u8 ;
struct cxd2880_tnrdmd {scalar_t__ diver_mode; scalar_t__ state; int en_fef_intmtnt_base; int en_fef_intmtnt_lite; TYPE_1__* diver_sub; int /*<<< orphan*/  bandwidth; void* sys; int /*<<< orphan*/  frequency_khz; } ;
struct cxd2880_dvbt2_tune_param {int profile; int /*<<< orphan*/  bandwidth; int /*<<< orphan*/  center_freq_khz; } ;
struct TYPE_2__ {int /*<<< orphan*/  bandwidth; void* sys; int /*<<< orphan*/  frequency_khz; scalar_t__ state; } ;

/* Variables and functions */
 void* CXD2880_DTV_SYS_DVBT2 ; 
#define  CXD2880_DVBT2_PROFILE_ANY 130 
#define  CXD2880_DVBT2_PROFILE_BASE 129 
#define  CXD2880_DVBT2_PROFILE_LITE 128 
 scalar_t__ CXD2880_TNRDMD_DIVERMODE_MAIN ; 
 scalar_t__ CXD2880_TNRDMD_DIVERMODE_SUB ; 
 scalar_t__ CXD2880_TNRDMD_STATE_ACTIVE ; 
 scalar_t__ CXD2880_TNRDMD_STATE_SLEEP ; 
 int EINVAL ; 
 int cxd2880_tnrdmd_common_tune_setting2 (struct cxd2880_tnrdmd*,void*,int) ; 

int cxd2880_tnrdmd_dvbt2_tune2(struct cxd2880_tnrdmd *tnr_dmd,
			       struct cxd2880_dvbt2_tune_param
			       *tune_param)
{
	u8 en_fef_intmtnt_ctrl = 1;
	int ret;

	if (!tnr_dmd || !tune_param)
		return -EINVAL;

	if (tnr_dmd->diver_mode == CXD2880_TNRDMD_DIVERMODE_SUB)
		return -EINVAL;

	if (tnr_dmd->state != CXD2880_TNRDMD_STATE_SLEEP &&
	    tnr_dmd->state != CXD2880_TNRDMD_STATE_ACTIVE)
		return -EINVAL;

	switch (tune_param->profile) {
	case CXD2880_DVBT2_PROFILE_BASE:
		en_fef_intmtnt_ctrl = tnr_dmd->en_fef_intmtnt_base;
		break;
	case CXD2880_DVBT2_PROFILE_LITE:
		en_fef_intmtnt_ctrl = tnr_dmd->en_fef_intmtnt_lite;
		break;
	case CXD2880_DVBT2_PROFILE_ANY:
		if (tnr_dmd->en_fef_intmtnt_base &&
		    tnr_dmd->en_fef_intmtnt_lite)
			en_fef_intmtnt_ctrl = 1;
		else
			en_fef_intmtnt_ctrl = 0;
		break;
	default:
		return -EINVAL;
	}

	ret =
	    cxd2880_tnrdmd_common_tune_setting2(tnr_dmd,
						CXD2880_DTV_SYS_DVBT2,
						en_fef_intmtnt_ctrl);
	if (ret)
		return ret;

	tnr_dmd->state = CXD2880_TNRDMD_STATE_ACTIVE;
	tnr_dmd->frequency_khz = tune_param->center_freq_khz;
	tnr_dmd->sys = CXD2880_DTV_SYS_DVBT2;
	tnr_dmd->bandwidth = tune_param->bandwidth;

	if (tnr_dmd->diver_mode == CXD2880_TNRDMD_DIVERMODE_MAIN) {
		tnr_dmd->diver_sub->state = CXD2880_TNRDMD_STATE_ACTIVE;
		tnr_dmd->diver_sub->frequency_khz = tune_param->center_freq_khz;
		tnr_dmd->diver_sub->sys = CXD2880_DTV_SYS_DVBT2;
		tnr_dmd->diver_sub->bandwidth = tune_param->bandwidth;
	}

	return 0;
}