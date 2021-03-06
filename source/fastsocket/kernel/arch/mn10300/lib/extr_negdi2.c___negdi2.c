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
struct TYPE_2__ {int high; scalar_t__ low; } ;
union DWunion {int /*<<< orphan*/  ll; TYPE_1__ s; } ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  s64 ;

/* Variables and functions */

s64 __negdi2(s64 u)
{
	union DWunion w;
	union DWunion uu;

	uu.ll = u;

	w.s.low = -uu.s.low;
	w.s.high = -uu.s.high - ((u32) w.s.low > 0);

	return w.ll;
}