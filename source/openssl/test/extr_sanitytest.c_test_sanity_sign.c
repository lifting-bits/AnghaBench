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
 int /*<<< orphan*/  INT_MAX ; 
 int INT_MIN ; 
 int /*<<< orphan*/  LONG_MAX ; 
 int LONG_MIN ; 
 int /*<<< orphan*/  TEST_int_eq (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_long_eq (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int test_sanity_sign(void)
{
    /* Check that values with sign bit 1 and value bits 0 are valid */
    if (!TEST_int_eq(-(INT_MIN + 1), INT_MAX)
        || !TEST_long_eq(-(LONG_MIN + 1), LONG_MAX))
        return 0;
    return 1;
}