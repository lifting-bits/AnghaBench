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
 int test_intern (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uint32_test_package ; 

__attribute__((used)) static int test_uint32(void)
{
    return test_intern(&uint32_test_package);
}