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
typedef  int /*<<< orphan*/  AVFilterFormats ;

/* Variables and functions */
 int /*<<< orphan*/  FORMATS_CHANGEREF (int /*<<< orphan*/ **,int /*<<< orphan*/ **) ; 

void ff_formats_changeref(AVFilterFormats **oldref, AVFilterFormats **newref)
{
    FORMATS_CHANGEREF(oldref, newref);
}