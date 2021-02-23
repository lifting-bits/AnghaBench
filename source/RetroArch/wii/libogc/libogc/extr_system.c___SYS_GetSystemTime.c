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
typedef  scalar_t__ s64 ;

/* Variables and functions */
 int /*<<< orphan*/  _CPU_ISR_Disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _CPU_ISR_Restore (int /*<<< orphan*/ ) ; 
 scalar_t__ gettime () ; 

s64 __SYS_GetSystemTime()
{
	u32 level;
	s64 now;
	s64 *pBootTime = (s64*)0x800030d8;

	_CPU_ISR_Disable(level);
	now = gettime();
	now += *pBootTime;
	_CPU_ISR_Restore(level);
	return now;
}