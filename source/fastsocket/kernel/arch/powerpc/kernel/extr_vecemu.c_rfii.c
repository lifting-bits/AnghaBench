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

__attribute__((used)) static unsigned int rfii(unsigned int x)
{
	int exp, mask;

	exp = ((x >> 23) & 0xff) - 127;
	if (exp == 128 && (x & 0x7fffff) != 0)
		return x | 0x400000;	/* NaN -> make it a QNaN */
	if (exp >= 23)
		return x;		/* it's an integer already (or Inf) */
	if ((x & 0x7fffffff) == 0)
		return x;		/* +/-0 -> +/-0 */
	if (exp < 0)
		/* 0 < |x| < 1.0 rounds to +/- 1.0 */
		return (x & 0x80000000) | 0x3f800000;
	mask = 0x7fffff >> exp;
	/* mantissa overflows into exponent - that's OK,
	   it can't overflow into the sign bit */
	return (x + mask) & ~mask;
}