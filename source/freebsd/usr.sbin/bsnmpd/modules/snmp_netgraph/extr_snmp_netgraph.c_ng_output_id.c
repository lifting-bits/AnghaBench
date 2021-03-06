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
typedef  int /*<<< orphan*/  u_int ;
typedef  int ng_ID_t ;

/* Variables and functions */
 int NG_PATHSIZ ; 
 int ng_output (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

int
ng_output_id(ng_ID_t node, u_int cookie, u_int opcode,
    const void *arg, size_t arglen)
{
	char path[NG_PATHSIZ];

	sprintf(path, "[%x]:", node);
	return (ng_output(path, cookie, opcode, arg, arglen));
}