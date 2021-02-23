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
typedef  int /*<<< orphan*/  int64_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  _ftelli64 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ftello (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ftello64 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int64_t ftell_x(FILE *fp)
{
#if defined(WIN32) && defined(__GNUC__)
    return ftello64(fp);
#elif defined(WIN32) && defined(_MSC_VER)
    return _ftelli64(fp);
#else
    return ftello(fp);
#endif
}