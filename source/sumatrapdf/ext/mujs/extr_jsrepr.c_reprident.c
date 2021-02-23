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
typedef  int /*<<< orphan*/  js_State ;
typedef  int /*<<< orphan*/  js_Buffer ;

/* Variables and functions */
 scalar_t__ isalpha (char const) ; 
 scalar_t__ isdigit (char const) ; 
 int /*<<< orphan*/  js_puts (int /*<<< orphan*/ *,int /*<<< orphan*/ **,char const*) ; 
 int /*<<< orphan*/  reprstr (int /*<<< orphan*/ *,int /*<<< orphan*/ **,char const*) ; 

__attribute__((used)) static void reprident(js_State *J, js_Buffer **sb, const char *name)
{
	const char *p = name;
	if (isdigit(*p))
		while (isdigit(*p))
			++p;
	else if (isalpha(*p) || *p == '_')
		while (isdigit(*p) || isalpha(*p) || *p == '_')
			++p;
	if (p > name && *p == 0)
		js_puts(J, sb, name);
	else
		reprstr(J, sb, name);
}