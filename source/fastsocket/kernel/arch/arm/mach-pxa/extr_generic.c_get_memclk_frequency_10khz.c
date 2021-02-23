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
 scalar_t__ cpu_is_pxa25x () ; 
 scalar_t__ cpu_is_pxa27x () ; 
 unsigned int pxa25x_get_memclk_frequency_10khz () ; 
 unsigned int pxa27x_get_memclk_frequency_10khz () ; 
 unsigned int pxa3xx_get_memclk_frequency_10khz () ; 

unsigned int get_memclk_frequency_10khz(void)
{
	if (cpu_is_pxa25x())
		return pxa25x_get_memclk_frequency_10khz();
	else if (cpu_is_pxa27x())
		return pxa27x_get_memclk_frequency_10khz();
	else
		return pxa3xx_get_memclk_frequency_10khz();
}