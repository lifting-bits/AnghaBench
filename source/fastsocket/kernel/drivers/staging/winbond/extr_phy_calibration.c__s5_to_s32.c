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
typedef  int u32 ;
typedef  int s32 ;

/* Variables and functions */
 int BIT (int) ; 

s32 _s5_to_s32(u32 data)
{
    s32     val;

    val = (data & 0x000F);

    if ((data & BIT(4)) != 0)
    {
        val |= 0xFFFFFFF0;
    }

    return val;
}