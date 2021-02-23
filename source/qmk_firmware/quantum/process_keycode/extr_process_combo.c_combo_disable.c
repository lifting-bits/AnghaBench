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

/* Variables and functions */
 int b_combo_enable ; 
 int /*<<< orphan*/  dump_key_buffer (int) ; 
 int is_active ; 
 scalar_t__ timer ; 

void combo_disable(void) {
    b_combo_enable = is_active = false;
    timer                      = 0;
    dump_key_buffer(true);
}