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
typedef  int /*<<< orphan*/  ERR_STRING_DATA ;

/* Variables and functions */
 scalar_t__ ERR_load_ERR_strings () ; 
 int /*<<< orphan*/  err_load_strings (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  err_patch (int,int /*<<< orphan*/ *) ; 

int ERR_load_strings(int lib, ERR_STRING_DATA *str)
{
    if (ERR_load_ERR_strings() == 0)
        return 0;

    err_patch(lib, str);
    err_load_strings(str);
    return 1;
}