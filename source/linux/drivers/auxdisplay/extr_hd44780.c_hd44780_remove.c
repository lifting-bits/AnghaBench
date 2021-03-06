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
struct platform_device {int dummy; } ;
struct charlcd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  charlcd_free (struct charlcd*) ; 
 int /*<<< orphan*/  charlcd_unregister (struct charlcd*) ; 
 struct charlcd* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int hd44780_remove(struct platform_device *pdev)
{
	struct charlcd *lcd = platform_get_drvdata(pdev);

	charlcd_unregister(lcd);

	charlcd_free(lcd);
	return 0;
}