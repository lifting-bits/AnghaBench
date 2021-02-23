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
 int _wchdir (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wconvert (char const*) ; 
 int /*<<< orphan*/  wdirname ; 
 int /*<<< orphan*/  wfree (char const*) ; 

__attribute__((used)) static __inline int _chdirU(const char *dirname)
{
	int ret;
	wconvert(dirname);
	ret = _wchdir(wdirname);
	wfree(dirname);
	return ret;
}