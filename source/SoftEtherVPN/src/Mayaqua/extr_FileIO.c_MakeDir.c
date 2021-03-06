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
 int MakeDirW (int /*<<< orphan*/ *) ; 

bool MakeDir(char *name)
{
	wchar_t *name_w = CopyStrToUni(name);
	bool ret = MakeDirW(name_w);

	Free(name_w);

	return ret;
}