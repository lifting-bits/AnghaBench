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
struct TYPE_2__ {int x; int y; } ;

/* Variables and functions */
 TYPE_1__ ui ; 
 int /*<<< orphan*/  ui_invalidate () ; 

__attribute__((used)) static void on_motion(int x, int y)
{
	ui.x = x;
	ui.y = y;
	ui_invalidate();
}