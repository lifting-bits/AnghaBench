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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */

int syscall2( int number, uint32_t p1, uint32_t p2 ){
	int ret;

	asm volatile ("		   \
		mov %1, %%eax	\n \
		mov %2, %%ebx	\n \
		mov %3, %%ecx	\n \
		int $0x80	\n \
		mov %%eax, %0"	
		: "=g" (ret) 
		: "g" (number), "g" (p1), "g" (p2)
	);
	return ret;
}