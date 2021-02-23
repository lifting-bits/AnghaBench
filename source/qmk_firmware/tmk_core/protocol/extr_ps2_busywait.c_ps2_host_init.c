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
 int /*<<< orphan*/  clock_init () ; 
 int /*<<< orphan*/  data_init () ; 
 int /*<<< orphan*/  inhibit () ; 
 int /*<<< orphan*/  wait_ms (int) ; 

void ps2_host_init(void) {
    clock_init();
    data_init();

    // POR(150-2000ms) plus BAT(300-500ms) may take 2.5sec([3]p.20)
    wait_ms(2500);

    inhibit();
}