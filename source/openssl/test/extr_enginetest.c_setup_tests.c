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
 int /*<<< orphan*/  ADD_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_note (char*) ; 
 int /*<<< orphan*/  test_engines ; 
 int /*<<< orphan*/  test_redirect ; 

int setup_tests(void)
{
#ifdef OPENSSL_NO_ENGINE
    TEST_note("No ENGINE support");
#else
    ADD_TEST(test_engines);
    ADD_TEST(test_redirect);
#endif
    return 1;
}