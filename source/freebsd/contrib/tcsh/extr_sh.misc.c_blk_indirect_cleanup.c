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
typedef  int /*<<< orphan*/  Char ;

/* Variables and functions */
 int /*<<< orphan*/  blkfree (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  xfree (int /*<<< orphan*/ ***) ; 

void
blk_indirect_cleanup(void *xptr)
{
    Char ***ptr;

    ptr = xptr;
    blkfree(*ptr);
    xfree(ptr);
}