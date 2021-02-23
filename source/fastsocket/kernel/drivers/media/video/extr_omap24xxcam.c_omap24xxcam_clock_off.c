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
struct omap24xxcam_device {int /*<<< orphan*/  ick; int /*<<< orphan*/  fck; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void omap24xxcam_clock_off(struct omap24xxcam_device *cam)
{
	clk_disable(cam->fck);
	clk_disable(cam->ick);
}