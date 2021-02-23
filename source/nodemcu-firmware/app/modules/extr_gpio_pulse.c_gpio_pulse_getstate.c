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
typedef  int /*<<< orphan*/  pulse_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int gpio_pulse_push_state (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * luaL_checkudata (int /*<<< orphan*/ *,int,char*) ; 

__attribute__((used)) static int gpio_pulse_getstate(lua_State *L) {
  pulse_t *pulser = luaL_checkudata(L, 1, "gpio.pulse");

  return gpio_pulse_push_state(L, pulser);
}