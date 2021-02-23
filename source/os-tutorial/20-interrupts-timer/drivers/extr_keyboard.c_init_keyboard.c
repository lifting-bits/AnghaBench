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
 int /*<<< orphan*/  IRQ1 ; 
 int /*<<< orphan*/  keyboard_callback ; 
 int /*<<< orphan*/  register_interrupt_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void init_keyboard() {
   register_interrupt_handler(IRQ1, keyboard_callback); 
}