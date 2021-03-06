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
typedef  int /*<<< orphan*/  u32 ;
struct dss_reg {scalar_t__ idx; } ;
struct dss_device {scalar_t__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  __raw_readl (scalar_t__) ; 

__attribute__((used)) static inline u32 dss_read_reg(struct dss_device *dss, const struct dss_reg idx)
{
	return __raw_readl(dss->base + idx.idx);
}