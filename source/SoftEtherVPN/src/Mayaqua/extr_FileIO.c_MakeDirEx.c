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
typedef  int /*<<< orphan*/  wchar_t ;

/* Variables and functions */
 int /*<<< orphan*/ * CopyStrToUni (char*) ; 
 int /*<<< orphan*/  Free (int /*<<< orphan*/ *) ; 
 int MakeDirExW (int /*<<< orphan*/ *) ; 

bool MakeDirEx(char *name)
{
	bool ret;
	wchar_t *name_w = CopyStrToUni(name);

	ret = MakeDirExW(name_w);

	Free(name_w);

	return ret;
}