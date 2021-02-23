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
struct rtl8366_smi {int clk_delay; int cmd_read; int cmd_write; scalar_t__ num_ports; scalar_t__ cpu_port; int /*<<< orphan*/  num_mib_counters; int /*<<< orphan*/  mib_counters; int /*<<< orphan*/  num_vlan_mc; int /*<<< orphan*/ * ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct rtl8366_smi*) ; 
 int PTR_ERR (struct rtl8366_smi*) ; 
 scalar_t__ RTL8367B_CPU_PORT_NUM ; 
 scalar_t__ RTL8367B_NUM_PORTS ; 
 int /*<<< orphan*/  RTL8367B_NUM_VLANS ; 
 int /*<<< orphan*/  kfree (struct rtl8366_smi*) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,scalar_t__*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rtl8366_smi*) ; 
 int /*<<< orphan*/  rtl8366_smi_cleanup (struct rtl8366_smi*) ; 
 int rtl8366_smi_init (struct rtl8366_smi*) ; 
 struct rtl8366_smi* rtl8366_smi_probe (struct platform_device*) ; 
 int /*<<< orphan*/  rtl8367b_mib_counters ; 
 int /*<<< orphan*/  rtl8367b_smi_ops ; 
 int rtl8367b_switch_init (struct rtl8366_smi*) ; 

__attribute__((used)) static int  rtl8367b_probe(struct platform_device *pdev)
{
	struct rtl8366_smi *smi;
	int err;

	smi = rtl8366_smi_probe(pdev);
	if (IS_ERR(smi))
		return PTR_ERR(smi);

	smi->clk_delay = 1500;
	smi->cmd_read = 0xb9;
	smi->cmd_write = 0xb8;
	smi->ops = &rtl8367b_smi_ops;
	smi->num_ports = RTL8367B_NUM_PORTS;
	if (of_property_read_u32(pdev->dev.of_node, "cpu_port", &smi->cpu_port)
	    || smi->cpu_port >= smi->num_ports)
		smi->cpu_port = RTL8367B_CPU_PORT_NUM;
	smi->num_vlan_mc = RTL8367B_NUM_VLANS;
	smi->mib_counters = rtl8367b_mib_counters;
	smi->num_mib_counters = ARRAY_SIZE(rtl8367b_mib_counters);

	err = rtl8366_smi_init(smi);
	if (err)
		goto err_free_smi;

	platform_set_drvdata(pdev, smi);

	err = rtl8367b_switch_init(smi);
	if (err)
		goto err_clear_drvdata;

	return 0;

 err_clear_drvdata:
	platform_set_drvdata(pdev, NULL);
	rtl8366_smi_cleanup(smi);
 err_free_smi:
	kfree(smi);
	return err;
}