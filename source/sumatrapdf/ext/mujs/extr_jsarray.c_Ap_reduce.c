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

/* Variables and functions */
 int /*<<< orphan*/  js_call (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  js_copy (int /*<<< orphan*/ *,int) ; 
 int js_getlength (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int js_gettop (int /*<<< orphan*/ *) ; 
 scalar_t__ js_hasindex (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  js_iscallable (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  js_pushnumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  js_pushundefined (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  js_rot (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  js_typeerror (int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static void Ap_reduce(js_State *J)
{
	int hasinitial = js_gettop(J) >= 3;
	int k, len;

	if (!js_iscallable(J, 1))
		js_typeerror(J, "callback is not a function");

	len = js_getlength(J, 0);
	k = 0;

	if (len == 0 && !hasinitial)
		js_typeerror(J, "no initial value");

	/* initial value of accumulator */
	if (hasinitial)
		js_copy(J, 2);
	else {
		while (k < len)
			if (js_hasindex(J, 0, k++))
				break;
		if (k == len)
			js_typeerror(J, "no initial value");
	}

	while (k < len) {
		if (js_hasindex(J, 0, k)) {
			js_copy(J, 1);
			js_pushundefined(J);
			js_rot(J, 4); /* accumulator on top */
			js_rot(J, 4); /* property on top */
			js_pushnumber(J, k);
			js_copy(J, 0);
			js_call(J, 4); /* calculate new accumulator */
		}
		++k;
	}

	/* return accumulator */
}