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
struct fixed31_32 {int /*<<< orphan*/  value; } ;

/* Variables and functions */
 unsigned int clamp_ux_dy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 

unsigned int dc_fixpt_clamp_u0d14(struct fixed31_32 arg)
{
	return clamp_ux_dy(arg.value, 0, 14, 1);
}