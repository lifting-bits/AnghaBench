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

/* Variables and functions */
 int hci_uart_unregister_proto (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  llp ; 

int ll_deinit(void)
{
	return hci_uart_unregister_proto(&llp);
}