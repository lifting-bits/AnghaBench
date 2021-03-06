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
struct buffer_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bforget (struct buffer_head*) ; 
 int /*<<< orphan*/  clear_buffer_uptodate (struct buffer_head*) ; 

void extents_bforget(struct buffer_head *bh)
{
    clear_buffer_uptodate(bh);
    bforget(bh);
}