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
typedef  scalar_t__ uint64_t ;

/* Variables and functions */
 scalar_t__ compare_blk64 (scalar_t__*,scalar_t__) ; 
 scalar_t__ founddatablk (scalar_t__) ; 

__attribute__((used)) static int
find_blks64(uint64_t *buf, int size, uint64_t *wantedblk)
{
    int blk;
    for (blk = 0; blk < size; blk++) {
	if (buf[blk] == 0)
	    continue;
	if (compare_blk64(wantedblk, buf[blk])) {
	    if (founddatablk(buf[blk]))
		return 1;
	}
    }
    return 0;
}