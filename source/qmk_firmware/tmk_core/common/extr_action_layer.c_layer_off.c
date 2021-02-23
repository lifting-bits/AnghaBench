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
typedef  unsigned long uint8_t ;

/* Variables and functions */
 unsigned long layer_state ; 
 int /*<<< orphan*/  layer_state_set (unsigned long) ; 

void layer_off(uint8_t layer) { layer_state_set(layer_state & ~(1UL << layer)); }