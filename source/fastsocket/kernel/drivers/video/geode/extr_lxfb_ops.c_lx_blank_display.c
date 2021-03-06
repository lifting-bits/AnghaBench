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
struct lxfb_par {int output; } ;
struct fb_info {struct lxfb_par* par; } ;

/* Variables and functions */
 int EINVAL ; 
#define  FB_BLANK_HSYNC_SUSPEND 132 
#define  FB_BLANK_NORMAL 131 
#define  FB_BLANK_POWERDOWN 130 
#define  FB_BLANK_UNBLANK 129 
#define  FB_BLANK_VSYNC_SUSPEND 128 
 int /*<<< orphan*/  FP_PM ; 
 int FP_PM_P ; 
 int OUTPUT_PANEL ; 
 int /*<<< orphan*/  VP_DCFG ; 
 int VP_DCFG_CRT_EN ; 
 int VP_DCFG_DAC_BL_EN ; 
 int VP_DCFG_HSYNC_EN ; 
 int VP_DCFG_VSYNC_EN ; 
 int /*<<< orphan*/  VP_MISC ; 
 int VP_MISC_DACPWRDN ; 
 int read_fp (struct lxfb_par*,int /*<<< orphan*/ ) ; 
 int read_vp (struct lxfb_par*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_fp (struct lxfb_par*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  write_vp (struct lxfb_par*,int /*<<< orphan*/ ,int) ; 

int lx_blank_display(struct fb_info *info, int blank_mode)
{
	struct lxfb_par *par = info->par;
	u32 dcfg, misc, fp_pm;
	int blank, hsync, vsync;

	/* CRT power saving modes. */
	switch (blank_mode) {
	case FB_BLANK_UNBLANK:
		blank = 0; hsync = 1; vsync = 1;
		break;
	case FB_BLANK_NORMAL:
		blank = 1; hsync = 1; vsync = 1;
		break;
	case FB_BLANK_VSYNC_SUSPEND:
		blank = 1; hsync = 1; vsync = 0;
		break;
	case FB_BLANK_HSYNC_SUSPEND:
		blank = 1; hsync = 0; vsync = 1;
		break;
	case FB_BLANK_POWERDOWN:
		blank = 1; hsync = 0; vsync = 0;
		break;
	default:
		return -EINVAL;
	}

	dcfg = read_vp(par, VP_DCFG);
	dcfg &= ~(VP_DCFG_DAC_BL_EN | VP_DCFG_HSYNC_EN | VP_DCFG_VSYNC_EN |
			VP_DCFG_CRT_EN);
	if (!blank)
		dcfg |= VP_DCFG_DAC_BL_EN | VP_DCFG_CRT_EN;
	if (hsync)
		dcfg |= VP_DCFG_HSYNC_EN;
	if (vsync)
		dcfg |= VP_DCFG_VSYNC_EN;

	write_vp(par, VP_DCFG, dcfg);

	misc = read_vp(par, VP_MISC);

	if (vsync && hsync)
		misc &= ~VP_MISC_DACPWRDN;
	else
		misc |= VP_MISC_DACPWRDN;

	write_vp(par, VP_MISC, misc);

	/* Power on/off flat panel */

	if (par->output & OUTPUT_PANEL) {
		fp_pm = read_fp(par, FP_PM);
		if (blank_mode == FB_BLANK_POWERDOWN)
			fp_pm &= ~FP_PM_P;
		else
			fp_pm |= FP_PM_P;
		write_fp(par, FP_PM, fp_pm);
	}

	return 0;
}