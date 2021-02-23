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
typedef  int /*<<< orphan*/  int64_t ;

/* Variables and functions */
 int UTIL_ltoa_radix (int /*<<< orphan*/ ,char*,int) ; 

int UTIL_ltoa(int64_t value, char *dest) { return UTIL_ltoa_radix(value, dest, 10); }