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
typedef  int /*<<< orphan*/  qhandle_t ;

/* Variables and functions */
 int /*<<< orphan*/  UI_R_REGISTERSHADERNOMIP ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ,char const*) ; 

qhandle_t trap_R_RegisterShaderNoMip( const char *name ) {
	return syscall( UI_R_REGISTERSHADERNOMIP, name );
}