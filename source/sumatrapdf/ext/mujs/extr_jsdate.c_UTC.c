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
 double DaylightSavingTA (double) ; 
 double LocalTZA () ; 

__attribute__((used)) static double UTC(double loc)
{
	return loc - LocalTZA() - DaylightSavingTA(loc - LocalTZA());
}