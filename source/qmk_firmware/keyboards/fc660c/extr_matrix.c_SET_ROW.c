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
typedef  int uint8_t ;

/* Variables and functions */
 int PORTD ; 

__attribute__((used)) static inline void SET_ROW(uint8_t ROW)
{
    // set row with unabling key
    PORTD = (PORTD & 0x0F) | (1<<7) | ((ROW & 0x07) << 4);
}