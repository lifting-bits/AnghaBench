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
 int /*<<< orphan*/  BOTLIB_PC_ADD_GLOBAL_DEFINE ; 
 int syscall (int /*<<< orphan*/ ,char*) ; 

int trap_BotLibDefine(char *string) {
	return syscall( BOTLIB_PC_ADD_GLOBAL_DEFINE, string );
}