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
typedef  int /*<<< orphan*/  data ;
typedef  int __u64 ;

/* Variables and functions */

__attribute__((used)) static inline void ubd_set_bit(__u64 bit, unsigned char *data)
{
	__u64 n;
	int bits, off;

	bits = sizeof(data[0]) * 8;
	n = bit / bits;
	off = bit % bits;
	data[n] |= (1 << off);
}