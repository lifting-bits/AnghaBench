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
typedef  int /*<<< orphan*/  fz_css_number ;
typedef  int /*<<< orphan*/  fz_css_match ;

/* Variables and functions */
 int /*<<< orphan*/  number_from_value (int /*<<< orphan*/ ,float,int) ; 
 int /*<<< orphan*/  value_from_property (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static fz_css_number
number_from_property(fz_css_match *match, const char *property, float initial, int initial_unit)
{
	return number_from_value(value_from_property(match, property), initial, initial_unit);
}