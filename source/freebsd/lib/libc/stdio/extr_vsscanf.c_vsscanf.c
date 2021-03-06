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
typedef  int /*<<< orphan*/  __va_list ;

/* Variables and functions */
 int /*<<< orphan*/  __get_locale () ; 
 int vsscanf_l (char const*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

int
vsscanf(const char * __restrict str, const char * __restrict fmt,
	__va_list ap)
{
	return vsscanf_l(str, __get_locale(), fmt, ap);
}