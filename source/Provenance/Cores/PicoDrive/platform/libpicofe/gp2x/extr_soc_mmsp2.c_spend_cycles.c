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

__attribute__((used)) static __attribute__((noinline)) void spend_cycles(int c)
{
	asm volatile(
		"0: subs %0, %0, #1 ;"
		"bgt 0b"
		: "=r" (c) : "0" (c) : "cc");
}