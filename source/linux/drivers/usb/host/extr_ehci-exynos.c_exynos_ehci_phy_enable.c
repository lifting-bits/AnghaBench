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
struct usb_hcd {int dummy; } ;
struct exynos_ehci_hcd {int /*<<< orphan*/ * phy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int PHY_NUMBER ; 
 struct usb_hcd* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  phy_power_off (int /*<<< orphan*/ ) ; 
 int phy_power_on (int /*<<< orphan*/ ) ; 
 struct exynos_ehci_hcd* to_exynos_ehci (struct usb_hcd*) ; 

__attribute__((used)) static int exynos_ehci_phy_enable(struct device *dev)
{
	struct usb_hcd *hcd = dev_get_drvdata(dev);
	struct exynos_ehci_hcd *exynos_ehci = to_exynos_ehci(hcd);
	int i;
	int ret = 0;

	for (i = 0; ret == 0 && i < PHY_NUMBER; i++)
		if (!IS_ERR(exynos_ehci->phy[i]))
			ret = phy_power_on(exynos_ehci->phy[i]);
	if (ret)
		for (i--; i >= 0; i--)
			if (!IS_ERR(exynos_ehci->phy[i]))
				phy_power_off(exynos_ehci->phy[i]);

	return ret;
}