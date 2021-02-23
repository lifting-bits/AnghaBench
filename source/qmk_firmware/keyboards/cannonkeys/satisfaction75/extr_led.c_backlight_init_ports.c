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
struct TYPE_2__ {int /*<<< orphan*/  level; scalar_t__ breathing; scalar_t__ enable; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIOA ; 
 int /*<<< orphan*/  PAL_MODE_ALTERNATE (int) ; 
 int /*<<< orphan*/  PWMD3 ; 
 int /*<<< orphan*/  backlight_set (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  breathing_enable () ; 
 TYPE_1__ kb_backlight_config ; 
 int /*<<< orphan*/  palSetPadMode (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pwmCFG ; 
 int /*<<< orphan*/  pwmStart (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void backlight_init_ports(void) {
  palSetPadMode(GPIOA, 6, PAL_MODE_ALTERNATE(1));
  pwmStart(&PWMD3, &pwmCFG);
  if(kb_backlight_config.enable){
    if(kb_backlight_config.breathing){
      breathing_enable();
    } else{
      backlight_set(kb_backlight_config.level);
    }
  } else {
    backlight_set(0);
  }
}