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
struct lcd_panel {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LCD_PANEL_BACKLIGHT_GPIO ; 
 int /*<<< orphan*/  LCD_PANEL_ENABLE_GPIO ; 
 int /*<<< orphan*/  LCD_PANEL_QVGA_GPIO ; 
 int /*<<< orphan*/  LCD_PANEL_RESET_GPIO ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ldp_panel_cleanup(struct lcd_panel *panel)
{
	gpio_free(LCD_PANEL_BACKLIGHT_GPIO);
	gpio_free(LCD_PANEL_ENABLE_GPIO);
	gpio_free(LCD_PANEL_QVGA_GPIO);
	gpio_free(LCD_PANEL_RESET_GPIO);
}