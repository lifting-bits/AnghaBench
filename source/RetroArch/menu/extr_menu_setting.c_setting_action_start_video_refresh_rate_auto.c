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
typedef  int /*<<< orphan*/  rarch_setting_t ;

/* Variables and functions */
 int /*<<< orphan*/  video_driver_monitor_reset () ; 

__attribute__((used)) static int setting_action_start_video_refresh_rate_auto(
      rarch_setting_t *setting)
{
   (void)setting;

   video_driver_monitor_reset();
   return 0;
}