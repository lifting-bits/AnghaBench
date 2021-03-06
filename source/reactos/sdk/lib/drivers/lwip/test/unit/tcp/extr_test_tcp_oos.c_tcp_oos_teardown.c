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
 int /*<<< orphan*/ * netif_default ; 
 int /*<<< orphan*/ * netif_list ; 
 int /*<<< orphan*/  tcp_remove_all () ; 

__attribute__((used)) static void
tcp_oos_teardown(void)
{
  tcp_remove_all();
  netif_list = NULL;
  netif_default = NULL;
}