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
 char* strchr (char const*,char) ; 
 size_t strspn (char const*,char*) ; 

__attribute__((used)) static int is_glob(const char *path)
{
#if HAVE_GLOB
    size_t span = 0;
    const char *p = path;

    while (p = strchr(p, '%')) {
        if (*(++p) == '%') {
            ++p;
            continue;
        }
        if (span = strspn(p, "*?[]{}"))
            break;
    }
    /* Did we hit a glob char or get to the end? */
    return span != 0;
#else
    return 0;
#endif
}