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
struct cxl_afu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CXL_AFU_Cntl_An_E ; 
 int /*<<< orphan*/  CXL_AFU_Cntl_An_ES_Enabled ; 
 int /*<<< orphan*/  CXL_AFU_Cntl_An_ES_MASK ; 
 int afu_control (struct cxl_afu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_devel (char*) ; 

__attribute__((used)) static int afu_enable(struct cxl_afu *afu)
{
	pr_devel("AFU enable request\n");

	return afu_control(afu, CXL_AFU_Cntl_An_E, 0,
			   CXL_AFU_Cntl_An_ES_Enabled,
			   CXL_AFU_Cntl_An_ES_MASK, true);
}