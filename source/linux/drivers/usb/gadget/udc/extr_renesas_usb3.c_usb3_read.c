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
typedef  scalar_t__ u32 ;
struct renesas_usb3 {scalar_t__ reg; } ;

/* Variables and functions */
 scalar_t__ ioread32 (scalar_t__) ; 

__attribute__((used)) static u32 usb3_read(struct renesas_usb3 *usb3, u32 offs)
{
	return ioread32(usb3->reg + offs);
}