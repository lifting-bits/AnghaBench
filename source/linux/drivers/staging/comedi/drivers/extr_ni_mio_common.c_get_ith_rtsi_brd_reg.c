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
struct ni_private {int rtsi_shared_mux_reg; scalar_t__ is_m_series; } ;
struct comedi_device {struct ni_private* private; } ;

/* Variables and functions */

__attribute__((used)) static int get_ith_rtsi_brd_reg(int i, struct comedi_device *dev)
{
	struct ni_private *devpriv = dev->private;
	int reg_i_sz = 3; /* value for e-series */
	int reg_i_mask;
	int reg_i_shift;

	if (devpriv->is_m_series)
		reg_i_sz = 4;
	reg_i_mask = ~((~0) << reg_i_sz);
	reg_i_shift = i * reg_i_sz;

	return (devpriv->rtsi_shared_mux_reg >> reg_i_shift) & reg_i_mask;
}