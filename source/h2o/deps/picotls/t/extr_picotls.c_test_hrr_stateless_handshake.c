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
 int /*<<< orphan*/  TEST_HANDSHAKE_HRR_STATELESS ; 
 int /*<<< orphan*/  ok (int) ; 
 int /*<<< orphan*/  ptls_iovec_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int sc_callcnt ; 
 int /*<<< orphan*/  test_handshake (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void test_hrr_stateless_handshake(void)
{
    sc_callcnt = 0;
    test_handshake(ptls_iovec_init(NULL, 0), TEST_HANDSHAKE_HRR_STATELESS, 0, 0, 0);
    ok(sc_callcnt == 1);
}