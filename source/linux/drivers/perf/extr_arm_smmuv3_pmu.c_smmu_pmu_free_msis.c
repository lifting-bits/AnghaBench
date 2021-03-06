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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  platform_msi_domain_free_irqs (struct device*) ; 

__attribute__((used)) static void smmu_pmu_free_msis(void *data)
{
	struct device *dev = data;

	platform_msi_domain_free_irqs(dev);
}