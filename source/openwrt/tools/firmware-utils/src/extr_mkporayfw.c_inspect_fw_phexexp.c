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
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static inline void inspect_fw_phexexp(char *label,
                                      uint32_t val, uint32_t expval)
{
	printf("%-23s: 0x%08x ", label, val);

	if (val == expval) {
		printf("(ok)\n");
	} else {
		printf("(expected: 0x%08x)\n", expval);
	}
}