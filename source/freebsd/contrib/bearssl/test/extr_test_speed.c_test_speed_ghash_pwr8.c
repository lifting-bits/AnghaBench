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
typedef  scalar_t__ br_ghash ;

/* Variables and functions */
 scalar_t__ br_ghash_pwr8_get () ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  test_speed_ghash_inner (char*,scalar_t__) ; 

__attribute__((used)) static void
test_speed_ghash_pwr8(void)
{
	br_ghash gh;

	gh = br_ghash_pwr8_get();
	if (gh == 0) {
		printf("%-30s UNAVAILABLE\n", "GHASH (pwr8)");
		fflush(stdout);
	} else {
		test_speed_ghash_inner("GHASH (pwr8)", gh);
	}
}