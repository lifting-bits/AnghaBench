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
 int jsV_numbertointeger (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jsV_tonumber (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stackidx (int /*<<< orphan*/ *,int) ; 

int js_tointeger(js_State *J, int idx)
{
	return jsV_numbertointeger(jsV_tonumber(J, stackidx(J, idx)));
}