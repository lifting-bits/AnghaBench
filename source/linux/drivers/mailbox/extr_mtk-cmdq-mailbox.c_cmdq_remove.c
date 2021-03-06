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
struct cmdq {int /*<<< orphan*/  clock; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_unprepare (int /*<<< orphan*/ ) ; 
 struct cmdq* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int cmdq_remove(struct platform_device *pdev)
{
	struct cmdq *cmdq = platform_get_drvdata(pdev);

	clk_unprepare(cmdq->clock);

	return 0;
}