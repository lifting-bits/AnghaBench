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
 int /*<<< orphan*/  __get_locale () ; 
 unsigned long long strtoull_l (char const*,char**,int,int /*<<< orphan*/ ) ; 

unsigned long long
strtoull(const char * __restrict nptr, char ** __restrict endptr, int base)
{
	return strtoull_l(nptr, endptr, base, __get_locale());
}