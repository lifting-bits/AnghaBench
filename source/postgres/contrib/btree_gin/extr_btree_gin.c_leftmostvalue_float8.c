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
typedef  int /*<<< orphan*/  Datum ;

/* Variables and functions */
 int /*<<< orphan*/  Float8GetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_float8_infinity () ; 

__attribute__((used)) static Datum
leftmostvalue_float8(void)
{
	return Float8GetDatum(-get_float8_infinity());
}