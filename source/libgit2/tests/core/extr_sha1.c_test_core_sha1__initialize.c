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
 int /*<<< orphan*/  FIXTURE_DIR ; 
 int /*<<< orphan*/  cl_fixture_sandbox (int /*<<< orphan*/ ) ; 

void test_core_sha1__initialize(void)
{
	cl_fixture_sandbox(FIXTURE_DIR);
}