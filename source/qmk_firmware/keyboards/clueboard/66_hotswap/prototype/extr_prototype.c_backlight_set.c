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
typedef  scalar_t__ uint8_t ;

/* Variables and functions */
 int PORTD ; 

void backlight_set(uint8_t level) {
    if ( level == 0 ) {
        // Turn off light
        PORTD |= (1<<0); // Esc
        PORTD |= (1<<4); // Page Up
        PORTD |= (1<<1); // Arrows
    } else {
        // Turn on light
        PORTD &= ~(1<<0); // Esc
        PORTD &= ~(1<<4); // Page Up
        PORTD &= ~(1<<1); // Arrows
    }
}