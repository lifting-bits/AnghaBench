#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  btlog_lock; } ;
typedef  TYPE_1__ btlog_t ;

/* Variables and functions */
 int /*<<< orphan*/  simple_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
btlog_unlock(btlog_t *btlog)
{
	simple_unlock(&btlog->btlog_lock);
}