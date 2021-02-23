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
struct resource {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int intr_event_suspend_handler (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rman_get_irq_cookie (struct resource*) ; 

__attribute__((used)) static int
nexus_suspend_intr(device_t dev, device_t child, struct resource *irq)
{
	return (intr_event_suspend_handler(rman_get_irq_cookie(irq)));
}