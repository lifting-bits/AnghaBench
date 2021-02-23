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
 scalar_t__ valid_gb2312_head (unsigned int) ; 
 scalar_t__ valid_gb2312_tail (unsigned int) ; 

__attribute__((used)) static unsigned int check_mb_gb2312(const char * const start, const char * const end)
{
	return (valid_gb2312_head((unsigned int)start[0]) && end - start > 1 &&
			valid_gb2312_tail((unsigned int)start[1])) ? 2 : 0;
}