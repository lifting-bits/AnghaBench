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
typedef  int /*<<< orphan*/  mode_t ;
typedef  int /*<<< orphan*/  git_win32_path ;

/* Variables and functions */
 int _wchmod (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ git_win32_path_from_utf8 (int /*<<< orphan*/ ,char const*) ; 

int p_chmod(const char* path, mode_t mode)
{
	git_win32_path buf;

	if (git_win32_path_from_utf8(buf, path) < 0)
		return -1;

	return _wchmod(buf, mode);
}