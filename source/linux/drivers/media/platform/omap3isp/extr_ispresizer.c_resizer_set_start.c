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
typedef  int u32 ;
struct isp_res_device {int dummy; } ;
struct isp_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ISPRSZ_IN_START ; 
 int ISPRSZ_IN_START_HORZ_ST_MASK ; 
 int ISPRSZ_IN_START_HORZ_ST_SHIFT ; 
 int ISPRSZ_IN_START_VERT_ST_MASK ; 
 int ISPRSZ_IN_START_VERT_ST_SHIFT ; 
 int /*<<< orphan*/  OMAP3_ISP_IOMEM_RESZ ; 
 int /*<<< orphan*/  isp_reg_writel (struct isp_device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct isp_device* to_isp_device (struct isp_res_device*) ; 

__attribute__((used)) static void resizer_set_start(struct isp_res_device *res, u32 left, u32 top)
{
	struct isp_device *isp = to_isp_device(res);
	u32 rgval;

	rgval = (left << ISPRSZ_IN_START_HORZ_ST_SHIFT)
		& ISPRSZ_IN_START_HORZ_ST_MASK;
	rgval |= (top << ISPRSZ_IN_START_VERT_ST_SHIFT)
		 & ISPRSZ_IN_START_VERT_ST_MASK;

	isp_reg_writel(isp, rgval, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_IN_START);
}