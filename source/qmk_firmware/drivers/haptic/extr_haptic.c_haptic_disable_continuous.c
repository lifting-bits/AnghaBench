#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  raw; scalar_t__ cont; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_MODE ; 
 int /*<<< orphan*/  DRV_write (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  eeconfig_update_haptic (int /*<<< orphan*/ ) ; 
 TYPE_1__ haptic_config ; 
 int /*<<< orphan*/  xprintf (char*,scalar_t__) ; 

void haptic_disable_continuous(void) {
    haptic_config.cont = 0;
    xprintf("haptic_config.cont = %u\n", haptic_config.cont);
    eeconfig_update_haptic(haptic_config.raw);
#ifdef DRV2605L
    DRV_write(DRV_MODE, 0x00);
#endif
}