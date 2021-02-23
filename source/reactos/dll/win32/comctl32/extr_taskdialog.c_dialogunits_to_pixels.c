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
struct taskdialog_template_desc {int /*<<< orphan*/  y_baseunit; int /*<<< orphan*/  x_baseunit; } ;
typedef  int /*<<< orphan*/  LONG ;

/* Variables and functions */
 int /*<<< orphan*/  MulDiv (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void dialogunits_to_pixels(const struct taskdialog_template_desc *desc, LONG *width, LONG *height)
{
    if (width)
        *width = MulDiv(*width, desc->x_baseunit, 4);
    if (height)
        *height = MulDiv(*height, desc->y_baseunit, 8);
}