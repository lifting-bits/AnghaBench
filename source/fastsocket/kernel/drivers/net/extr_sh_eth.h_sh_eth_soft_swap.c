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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  swab32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void sh_eth_soft_swap(char *src, int len)
{
#ifdef __LITTLE_ENDIAN__
	u32 *p = (u32 *)src;
	u32 *maxp;
	maxp = p + ((len + sizeof(u32) - 1) / sizeof(u32));

	for (; p < maxp; p++)
		*p = swab32(*p);
#endif
}