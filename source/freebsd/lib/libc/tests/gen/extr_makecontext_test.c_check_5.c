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
 int /*<<< orphan*/  ATF_REQUIRE_EQ (int,int) ; 

__attribute__((used)) static void
check_5(int arg1, int arg2, int arg3, int arg4, int arg5)
{

	ATF_REQUIRE_EQ(arg1, 1);
	ATF_REQUIRE_EQ(arg2, 2);
	ATF_REQUIRE_EQ(arg3, 3);
	ATF_REQUIRE_EQ(arg4, 4);
	ATF_REQUIRE_EQ(arg5, 5);
}