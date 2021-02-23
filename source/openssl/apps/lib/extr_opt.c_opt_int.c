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
 int /*<<< orphan*/  opt_long (char const*,long*) ; 
 int /*<<< orphan*/  opt_printf_stderr (char*,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  prog ; 

int opt_int(const char *value, int *result)
{
    long l;

    if (!opt_long(value, &l))
        return 0;
    *result = (int)l;
    if (*result != l) {
        opt_printf_stderr("%s: Value \"%s\" outside integer range\n",
                          prog, value);
        return 0;
    }
    return 1;
}