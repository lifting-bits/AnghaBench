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
struct led_classdev {int dummy; } ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;

/* Variables and functions */
 int /*<<< orphan*/  AR71XX_RESET_GE1_PHY ; 
 int LED_FULL ; 
 int LED_OFF ; 
 scalar_t__ ath79_device_reset_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static enum led_brightness wndr3700_usb_led_get(struct led_classdev *cdev)
{
	return ath79_device_reset_get(AR71XX_RESET_GE1_PHY) ? LED_OFF : LED_FULL;
}