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
typedef  int /*<<< orphan*/  UINT ;

/* Variables and functions */
 char* GetTableStr (char*) ; 
 int /*<<< orphan*/  ToInt (char*) ; 

UINT GetTableInt(char *name)
{
	char *str;
	// Validate arguments
	if (name == NULL)
	{
		return 0;
	}

	str = GetTableStr(name);
	return ToInt(str);
}