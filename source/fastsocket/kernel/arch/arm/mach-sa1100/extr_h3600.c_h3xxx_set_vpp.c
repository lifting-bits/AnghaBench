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

/* Variables and functions */
 int /*<<< orphan*/  IPAQ_EGPIO_VPP_ON ; 
 int /*<<< orphan*/  assign_h3600_egpio (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void h3xxx_set_vpp(int vpp)
{
	assign_h3600_egpio(IPAQ_EGPIO_VPP_ON, vpp);
}