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
 int /*<<< orphan*/  assert_sorted (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cmp_int ; 

void test_core_qsort__sorted_array(void)
{
	int a[] = { 1, 10 };
	assert_sorted(a, cmp_int);
}