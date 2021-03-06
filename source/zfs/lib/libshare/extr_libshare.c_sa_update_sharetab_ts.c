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
typedef  int /*<<< orphan*/  sa_handle_t ;
typedef  int /*<<< orphan*/  sa_handle_impl_t ;

/* Variables and functions */
 int /*<<< orphan*/  update_sharetab (int /*<<< orphan*/ ) ; 

void
sa_update_sharetab_ts(sa_handle_t handle)
{
	sa_handle_impl_t impl_handle = (sa_handle_impl_t)handle;

	update_sharetab(impl_handle);
}