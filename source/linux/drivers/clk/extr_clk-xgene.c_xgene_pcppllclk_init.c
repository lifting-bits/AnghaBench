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
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PLL_TYPE_PCP ; 
 int /*<<< orphan*/  xgene_pllclk_init (struct device_node*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xgene_pcppllclk_init(struct device_node *np)
{
	xgene_pllclk_init(np, PLL_TYPE_PCP);
}