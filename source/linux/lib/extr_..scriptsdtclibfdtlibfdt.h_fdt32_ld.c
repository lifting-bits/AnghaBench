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
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  fdt32_t ;

/* Variables and functions */

__attribute__((used)) static inline uint32_t fdt32_ld(const fdt32_t *p)
{
	const uint8_t *bp = (const uint8_t *)p;

	return ((uint32_t)bp[0] << 24)
		| ((uint32_t)bp[1] << 16)
		| ((uint32_t)bp[2] << 8)
		| bp[3];
}