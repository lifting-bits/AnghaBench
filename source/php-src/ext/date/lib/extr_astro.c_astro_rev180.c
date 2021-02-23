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
 double INV360 ; 
 double floor (double) ; 

__attribute__((used)) static double astro_rev180( double x )
{
	return (x - 360.0 * floor(x * INV360 + 0.5));
}