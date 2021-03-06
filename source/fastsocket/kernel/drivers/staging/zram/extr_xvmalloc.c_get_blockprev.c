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
typedef  int u32 ;
struct block_header {int prev; } ;

/* Variables and functions */
 int PREV_MASK ; 

__attribute__((used)) static u32 get_blockprev(struct block_header *block)
{
	return block->prev & PREV_MASK;
}