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
struct vfe_device {scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ VFE_0_BUS_BDG_CMD ; 
 int /*<<< orphan*/  VFE_0_BUS_BDG_CMD_HALT_REQ ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void vfe_halt_request(struct vfe_device *vfe)
{
	writel_relaxed(VFE_0_BUS_BDG_CMD_HALT_REQ,
		       vfe->base + VFE_0_BUS_BDG_CMD);
}