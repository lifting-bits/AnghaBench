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
 int /*<<< orphan*/  ATF_REQUIRE (int) ; 
 int /*<<< orphan*/  ATF_REQUIRE_FEATURE (char*) ; 
 int O_CLOEXEC ; 
 int O_EXEC ; 
 int /*<<< orphan*/  open (char*,int) ; 
 int /*<<< orphan*/  rootfd ; 

__attribute__((used)) static void
check_capsicum(void)
{
	ATF_REQUIRE_FEATURE("security_capabilities");
	ATF_REQUIRE_FEATURE("security_capability_mode");

	ATF_REQUIRE((rootfd = open("/", O_EXEC | O_CLOEXEC)) >= 0);
}