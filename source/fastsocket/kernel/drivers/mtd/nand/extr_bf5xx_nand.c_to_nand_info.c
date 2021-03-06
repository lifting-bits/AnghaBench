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
struct bf5xx_nand_info {int dummy; } ;

/* Variables and functions */
 struct bf5xx_nand_info* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static struct bf5xx_nand_info *to_nand_info(struct platform_device *pdev)
{
	return platform_get_drvdata(pdev);
}