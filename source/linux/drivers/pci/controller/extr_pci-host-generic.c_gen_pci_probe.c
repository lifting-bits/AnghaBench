#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct pci_ecam_ops {int dummy; } ;
struct of_device_id {scalar_t__ data; } ;

/* Variables and functions */
 int /*<<< orphan*/  gen_pci_of_match ; 
 struct of_device_id* of_match_node (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pci_host_common_probe (struct platform_device*,struct pci_ecam_ops*) ; 

__attribute__((used)) static int gen_pci_probe(struct platform_device *pdev)
{
	const struct of_device_id *of_id;
	struct pci_ecam_ops *ops;

	of_id = of_match_node(gen_pci_of_match, pdev->dev.of_node);
	ops = (struct pci_ecam_ops *)of_id->data;

	return pci_host_common_probe(pdev, ops);
}