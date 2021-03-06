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
typedef  int /*<<< orphan*/  u16 ;
struct ep93xx_pata_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ep93xx_pata_write (struct ep93xx_pata_data*,int /*<<< orphan*/ ,unsigned long,int) ; 

__attribute__((used)) static void ep93xx_pata_write_data(struct ep93xx_pata_data *drv_data,
				   u16 value, unsigned long addr)
{
	ep93xx_pata_write(drv_data, value, addr, false);
}