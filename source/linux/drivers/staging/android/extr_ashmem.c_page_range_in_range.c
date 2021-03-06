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
struct ashmem_range {int dummy; } ;

/* Variables and functions */
 scalar_t__ page_in_range (struct ashmem_range*,size_t) ; 
 scalar_t__ page_range_subsumes_range (struct ashmem_range*,size_t,size_t) ; 

__attribute__((used)) static inline bool page_range_in_range(struct ashmem_range *range,
				       size_t start, size_t end)
{
	return page_in_range(range, start) || page_in_range(range, end) ||
		page_range_subsumes_range(range, start, end);
}