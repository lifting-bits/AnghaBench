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
typedef  int /*<<< orphan*/  cmsPipeline ;
typedef  int /*<<< orphan*/  cmsInt32Number ;

/* Variables and functions */
 int /*<<< orphan*/  Add3GammaCurves (int /*<<< orphan*/ *,double) ; 
 int /*<<< orphan*/  AddIdentityCLUT16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AddIdentityMatrix (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CheckFullLUT (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  DbgThread () ; 
 int /*<<< orphan*/ * cmsPipelineAlloc (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static
cmsInt32Number Check4Stage16LUT(void)
{
    cmsPipeline* lut = cmsPipelineAlloc(DbgThread(), 3, 3);

    AddIdentityMatrix(lut);
    AddIdentityCLUT16(lut);
    Add3GammaCurves(lut, 1.0);
    AddIdentityMatrix(lut);

    return CheckFullLUT(lut, 4);
}