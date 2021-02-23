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
 unsigned long spmf_mult () ; 
 unsigned long sysdiv_div_x_2 () ; 

__attribute__((used)) static unsigned long sys_to_ref(unsigned long rate)
{
	rate *= sysdiv_div_x_2();
	rate /= 2;
	rate /= spmf_mult();

	return rate;
}