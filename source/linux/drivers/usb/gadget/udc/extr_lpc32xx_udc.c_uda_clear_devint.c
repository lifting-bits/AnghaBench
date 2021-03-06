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
struct lpc32xx_udc {int /*<<< orphan*/  udp_baseaddr; } ;

/* Variables and functions */
 int /*<<< orphan*/  USBD_DEVINTCLR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void uda_clear_devint(struct lpc32xx_udc *udc, u32 mask)
{
	writel(mask, USBD_DEVINTCLR(udc->udp_baseaddr));
}