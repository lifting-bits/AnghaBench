#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ rw_sem; } ;
struct super_block {TYPE_1__ s_writers; } ;

/* Variables and functions */
 int SB_FREEZE_LEVELS ; 
 int /*<<< orphan*/  percpu_up_write (scalar_t__) ; 

__attribute__((used)) static void sb_freeze_unlock(struct super_block *sb)
{
	int level;

	for (level = SB_FREEZE_LEVELS - 1; level >= 0; level--)
		percpu_up_write(sb->s_writers.rw_sem + level);
}