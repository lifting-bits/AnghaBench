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
 int INVALID_IDX (int) ; 

__attribute__((used)) static inline uint32_t __offset_STAGE(uint32_t idx)
{
	switch (idx) {
		case 0: return 0x00000104;
		case 1: return 0x00000124;
		case 2: return 0x00000144;
		case 3: return 0x00000160;
		default: return INVALID_IDX(idx);
	}
}