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
 int /*<<< orphan*/  init_srcu_struct (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rcu_sync_torture_init () ; 
 int /*<<< orphan*/  srcu_ctl ; 

__attribute__((used)) static void srcu_torture_init(void)
{
	init_srcu_struct(&srcu_ctl);
	rcu_sync_torture_init();
}