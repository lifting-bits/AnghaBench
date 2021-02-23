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
 int __raw_readw (scalar_t__) ; 
 scalar_t__ mbox_base ; 

__attribute__((used)) static inline int mbox_read_reg(size_t ofs)
{
	return __raw_readw(mbox_base + ofs);
}