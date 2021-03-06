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
typedef  size_t UINT ;

/* Variables and functions */
 int IsPrintableAsciiChar (char) ; 
 size_t StrLen (char*) ; 

void EnPrintableAsciiStr(char *str, char replace)
{
	UINT i, len;
	// Validate arguments
	if (str == NULL)
	{
		return;
	}

	len = StrLen(str);

	for (i = 0;i < len;i++)
	{
		char c = str[i];

		if (IsPrintableAsciiChar(c) == false)
		{
			str[i] = replace;
		}
	}
}