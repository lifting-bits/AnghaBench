#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* buf_t ;
struct TYPE_3__ {int b_lflags; } ;

/* Variables and functions */
 int BL_SHADOW ; 

int
buf_shadow(buf_t bp)
{
	if (bp->b_lflags & BL_SHADOW)
		return 1;
	return 0;
}