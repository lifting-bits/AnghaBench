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
typedef  unsigned int uint64_t ;
struct bcache_device {int /*<<< orphan*/  stripe_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  do_div (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned int offset_to_stripe(struct bcache_device *d,
					uint64_t offset)
{
	do_div(offset, d->stripe_size);
	return offset;
}