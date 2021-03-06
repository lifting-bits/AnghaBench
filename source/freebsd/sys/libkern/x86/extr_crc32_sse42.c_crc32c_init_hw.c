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
 int LONG ; 
 int SHORT ; 
 int /*<<< orphan*/  crc32c_2long ; 
 int /*<<< orphan*/  crc32c_2short ; 
 int /*<<< orphan*/  crc32c_long ; 
 int /*<<< orphan*/  crc32c_short ; 
 int /*<<< orphan*/  crc32c_zeros (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
#ifndef _KERNEL
__attribute__((__constructor__))
#endif
crc32c_init_hw(void)
{
	crc32c_zeros(crc32c_long, LONG);
	crc32c_zeros(crc32c_2long, 2 * LONG);
	crc32c_zeros(crc32c_short, SHORT);
	crc32c_zeros(crc32c_2short, 2 * SHORT);
}