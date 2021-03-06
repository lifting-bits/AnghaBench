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
typedef  int /*<<< orphan*/  u16 ;
struct isp1760_udc {int /*<<< orphan*/  regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  isp1760_read32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 isp1760_udc_read(struct isp1760_udc *udc, u16 reg)
{
	return isp1760_read32(udc->regs, reg);
}