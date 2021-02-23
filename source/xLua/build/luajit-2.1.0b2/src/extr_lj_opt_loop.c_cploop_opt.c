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
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/ * lua_CFunction ;
typedef  int /*<<< orphan*/  TValue ;
typedef  int /*<<< orphan*/  LoopState ;

/* Variables and functions */
 int /*<<< orphan*/  UNUSED (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  loop_unroll (int /*<<< orphan*/ *) ; 

__attribute__((used)) static TValue *cploop_opt(lua_State *L, lua_CFunction dummy, void *ud)
{
  UNUSED(L); UNUSED(dummy);
  loop_unroll((LoopState *)ud);
  return NULL;
}