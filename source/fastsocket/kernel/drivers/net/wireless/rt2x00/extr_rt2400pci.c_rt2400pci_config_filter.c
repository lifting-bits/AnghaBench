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
struct rt2x00_dev {int /*<<< orphan*/  intf_ap_count; } ;

/* Variables and functions */
 unsigned int const FIF_CONTROL ; 
 unsigned int const FIF_FCSFAIL ; 
 unsigned int const FIF_PLCPFAIL ; 
 unsigned int const FIF_PROMISC_IN_BSS ; 
 int /*<<< orphan*/  RXCSR0 ; 
 int /*<<< orphan*/  RXCSR0_DROP_CONTROL ; 
 int /*<<< orphan*/  RXCSR0_DROP_CRC ; 
 int /*<<< orphan*/  RXCSR0_DROP_NOT_TO_ME ; 
 int /*<<< orphan*/  RXCSR0_DROP_PHYSICAL ; 
 int /*<<< orphan*/  RXCSR0_DROP_TODS ; 
 int /*<<< orphan*/  RXCSR0_DROP_VERSION_ERROR ; 
 int /*<<< orphan*/  rt2x00_set_field32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rt2x00mmio_register_read (struct rt2x00_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rt2x00mmio_register_write (struct rt2x00_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rt2400pci_config_filter(struct rt2x00_dev *rt2x00dev,
				    const unsigned int filter_flags)
{
	u32 reg;

	/*
	 * Start configuration steps.
	 * Note that the version error will always be dropped
	 * since there is no filter for it at this time.
	 */
	rt2x00mmio_register_read(rt2x00dev, RXCSR0, &reg);
	rt2x00_set_field32(&reg, RXCSR0_DROP_CRC,
			   !(filter_flags & FIF_FCSFAIL));
	rt2x00_set_field32(&reg, RXCSR0_DROP_PHYSICAL,
			   !(filter_flags & FIF_PLCPFAIL));
	rt2x00_set_field32(&reg, RXCSR0_DROP_CONTROL,
			   !(filter_flags & FIF_CONTROL));
	rt2x00_set_field32(&reg, RXCSR0_DROP_NOT_TO_ME,
			   !(filter_flags & FIF_PROMISC_IN_BSS));
	rt2x00_set_field32(&reg, RXCSR0_DROP_TODS,
			   !(filter_flags & FIF_PROMISC_IN_BSS) &&
			   !rt2x00dev->intf_ap_count);
	rt2x00_set_field32(&reg, RXCSR0_DROP_VERSION_ERROR, 1);
	rt2x00mmio_register_write(rt2x00dev, RXCSR0, reg);
}