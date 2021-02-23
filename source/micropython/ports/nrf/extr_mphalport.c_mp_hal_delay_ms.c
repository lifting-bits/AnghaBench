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
typedef  scalar_t__ mp_uint_t ;

/* Variables and functions */
 int /*<<< orphan*/  mp_hal_delay_us (int) ; 

void mp_hal_delay_ms(mp_uint_t ms)
{
    for (mp_uint_t i = 0; i < ms; i++)
    {
        mp_hal_delay_us(999);
    }
}