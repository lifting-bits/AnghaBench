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
typedef  scalar_t__ u32 ;
struct tegra_p2u {scalar_t__ const base; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel_relaxed (scalar_t__ const,scalar_t__ const) ; 

__attribute__((used)) static inline void p2u_writel(struct tegra_p2u *phy, const u32 value,
			      const u32 reg)
{
	writel_relaxed(value, phy->base + reg);
}