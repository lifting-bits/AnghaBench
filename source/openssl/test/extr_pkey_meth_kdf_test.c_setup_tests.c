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
 int /*<<< orphan*/  test_kdf_hkdf ; 
 int /*<<< orphan*/  test_kdf_scrypt ; 
 int /*<<< orphan*/  test_kdf_tls1_prf ; 

int setup_tests(void)
{
    ADD_TEST(test_kdf_tls1_prf);
    ADD_TEST(test_kdf_hkdf);
#ifndef OPENSSL_NO_SCRYPT
    ADD_TEST(test_kdf_scrypt);
#endif
    return 1;
}