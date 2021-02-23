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
typedef  char WCHAR ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (char*) ; 
 int /*<<< orphan*/  GetLocaleInfoW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOCALE_SDECIMAL ; 
 int /*<<< orphan*/  LOCALE_USER_DEFAULT ; 

__attribute__((used)) static WCHAR get_decimal_sep(void)
{
    static WCHAR sep;

    if(!sep)
    {
        WCHAR buf[] = {'.', 0};
        GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_SDECIMAL, buf, ARRAY_SIZE(buf));
        sep = buf[0];
    }
    return sep;
}