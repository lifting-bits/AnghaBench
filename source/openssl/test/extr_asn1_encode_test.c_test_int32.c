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
 int /*<<< orphan*/  int32_test_package ; 
 int test_intern (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int test_int32(void)
{
    return test_intern(&int32_test_package);
}