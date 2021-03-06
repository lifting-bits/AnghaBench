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
struct dispc_device {int dummy; } ;
typedef  enum omap_channel { ____Placeholder_omap_channel } omap_channel ;

/* Variables and functions */
 int /*<<< orphan*/  DISPC_MGR_FLD_TCKENABLE ; 
 int /*<<< orphan*/  mgr_fld_write (struct dispc_device*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void dispc_mgr_enable_trans_key(struct dispc_device *dispc,
				       enum omap_channel ch, bool enable)
{
	mgr_fld_write(dispc, ch, DISPC_MGR_FLD_TCKENABLE, enable);
}