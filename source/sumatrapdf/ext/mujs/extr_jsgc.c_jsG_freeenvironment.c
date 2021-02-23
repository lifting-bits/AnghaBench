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
typedef  int /*<<< orphan*/  js_Environment ;

/* Variables and functions */
 int /*<<< orphan*/  js_free (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void jsG_freeenvironment(js_State *J, js_Environment *env)
{
	js_free(J, env);
}