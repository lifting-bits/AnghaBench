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
 int /*<<< orphan*/  MADV_DONTNEED ; 
 size_t image_swap_pgsz ; 
 scalar_t__ madvise (void*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (void*,size_t) ; 
 size_t secsz ; 
 int /*<<< orphan*/  warn (char*) ; 

__attribute__((used)) static int
image_file_unmap(void *buffer, size_t sz)
{
	size_t unit;

	unit = (secsz > image_swap_pgsz) ? secsz : image_swap_pgsz;
	sz = (sz + unit - 1) & ~(unit - 1);
	if (madvise(buffer, sz, MADV_DONTNEED) != 0)
		warn("madvise");
	munmap(buffer, sz);
	return (0);
}