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
typedef  size_t timelib_sll ;

/* Variables and functions */
 size_t* d_table_common ; 
 size_t* d_table_leap ; 
 scalar_t__ timelib_is_leap (size_t) ; 

timelib_sll timelib_day_of_year(timelib_sll y, timelib_sll m, timelib_sll d)
{
	return (timelib_is_leap(y) ? d_table_leap[m] : d_table_common[m]) + d - 1;
}