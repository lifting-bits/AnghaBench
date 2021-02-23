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
 int pages_nohuge_impl (void*,size_t,int) ; 

__attribute__((used)) static bool
pages_nohuge_unaligned(void *addr, size_t size) {
	return pages_nohuge_impl(addr, size, false);
}