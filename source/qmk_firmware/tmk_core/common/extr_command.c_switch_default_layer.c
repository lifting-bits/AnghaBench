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
 int /*<<< orphan*/  clear_keyboard () ; 
 int /*<<< orphan*/  default_layer_set (unsigned long) ; 
 int /*<<< orphan*/  xprintf (char*,unsigned long) ; 

__attribute__((used)) static void switch_default_layer(uint8_t layer) {
    xprintf("L%d\n", layer);
    default_layer_set(1UL << layer);
    clear_keyboard();
}