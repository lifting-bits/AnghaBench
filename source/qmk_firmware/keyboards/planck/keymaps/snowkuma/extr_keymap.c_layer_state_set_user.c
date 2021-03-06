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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  _FUNCTION ; 
 int /*<<< orphan*/  _MOUSE ; 
 int /*<<< orphan*/  _REGEX ; 
 int /*<<< orphan*/  _SYMBOL ; 
 int /*<<< orphan*/  _THUMB ; 
 int /*<<< orphan*/  update_tri_layer_state (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _SYMBOL, _THUMB, _FUNCTION);
  state = update_tri_layer_state(state, _SYMBOL, _REGEX, _MOUSE);
  return state;
}