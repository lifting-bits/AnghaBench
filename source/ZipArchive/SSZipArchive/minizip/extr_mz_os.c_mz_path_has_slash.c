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
typedef  int int32_t ;

/* Variables and functions */
 int MZ_EXIST_ERROR ; 
 int MZ_OK ; 
 int /*<<< orphan*/  strlen (char const*) ; 

int32_t mz_path_has_slash(const char *path)
{
    int32_t path_len = (int32_t)strlen(path);
    if (path[path_len - 1] != '\\' && path[path_len - 1] != '/')
        return MZ_EXIST_ERROR;
    return MZ_OK;
}