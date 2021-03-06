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
struct blogic_adapter {scalar_t__ io_addr; } ;

/* Variables and functions */
 scalar_t__ BLOGIC_STATUS_REG ; 
 unsigned char inb (scalar_t__) ; 

__attribute__((used)) static inline unsigned char blogic_rdstatus(struct blogic_adapter *adapter)
{
	return inb(adapter->io_addr + BLOGIC_STATUS_REG);
}