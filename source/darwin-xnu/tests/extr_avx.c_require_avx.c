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
 int /*<<< orphan*/  T_SKIP (char*) ; 
 int _get_cpu_capabilities () ; 
 int kHasAVX1_0 ; 

void
require_avx(void) {
	if((_get_cpu_capabilities() & kHasAVX1_0) != kHasAVX1_0) {
		T_SKIP("AVX not supported on this system");
	}
}