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
typedef  int /*<<< orphan*/  br_ec_impl ;

/* Variables and functions */
 int /*<<< orphan*/  br_curve25519 ; 
 int /*<<< orphan*/ * br_ec_c25519_m62_get () ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  test_speed_ec_inner (char*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
test_speed_ec_c25519_m62(void)
{
	const br_ec_impl *ec;

	ec = br_ec_c25519_m62_get();
	if (ec != NULL) {
		test_speed_ec_inner("EC c25519_m62", ec, &br_curve25519);
	} else {
		printf("%-30s UNAVAILABLE\n", "EC c25519_m62");
	}
}