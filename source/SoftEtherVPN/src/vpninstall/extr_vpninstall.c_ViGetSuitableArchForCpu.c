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
typedef  int /*<<< orphan*/  VI_SETTING_ARCH ;
struct TYPE_2__ {int /*<<< orphan*/  x86; } ;

/* Variables and functions */
 TYPE_1__ setting ; 

VI_SETTING_ARCH *ViGetSuitableArchForCpu()
{
	return &setting.x86;
}