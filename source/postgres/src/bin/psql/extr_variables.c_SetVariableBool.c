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
typedef  int /*<<< orphan*/  VariableSpace ;

/* Variables and functions */
 int SetVariable (int /*<<< orphan*/ ,char const*,char*) ; 

bool
SetVariableBool(VariableSpace space, const char *name)
{
	return SetVariable(space, name, "on");
}