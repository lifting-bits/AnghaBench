#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  st_mode; } ;
typedef  TYPE_1__ stat_t ;
typedef  int U32 ;

/* Variables and functions */
 scalar_t__ S_ISLNK (int /*<<< orphan*/ ) ; 
 int lstat (char const*,TYPE_1__*) ; 

U32 UTIL_isLink(const char* infilename)
{
/* macro guards, as defined in : https://linux.die.net/man/2/lstat */
#if PLATFORM_POSIX_VERSION >= 200112L
    int r;
    stat_t statbuf;
    r = lstat(infilename, &statbuf);
    if (!r && S_ISLNK(statbuf.st_mode)) return 1;
#endif
    (void)infilename;
    return 0;
}