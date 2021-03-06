#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned int sx; } ;

/* Variables and functions */
 TYPE_1__ ieee754_csr ; 

__attribute__((used)) static inline int ieee754_sxtest(unsigned int n)
{
	return (ieee754_csr.sx & n);
}