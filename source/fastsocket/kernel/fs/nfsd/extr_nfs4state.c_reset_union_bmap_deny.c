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
 int /*<<< orphan*/  __clear_bit (int,unsigned long*) ; 

__attribute__((used)) static void
reset_union_bmap_deny(unsigned long deny, unsigned long *bmap)
{
	int i;
	for (i = 0; i < 4; i++) {
		if ((i & deny) != i)
			__clear_bit(i, bmap);
	}
}