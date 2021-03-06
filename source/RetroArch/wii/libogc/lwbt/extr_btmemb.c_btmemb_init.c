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
typedef  int /*<<< orphan*/  u32 ;
struct memb_blks {int num; int /*<<< orphan*/  size; int /*<<< orphan*/  mem; } ;

/* Variables and functions */
 int /*<<< orphan*/  MEMSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int MEM_ALIGN_SIZE (int /*<<< orphan*/ ) ; 

void btmemb_init(struct memb_blks *blk)
{
	MEMSET(blk->mem,0,(MEM_ALIGN_SIZE(blk->size)+sizeof(u32))*blk->num);
}