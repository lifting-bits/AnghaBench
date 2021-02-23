#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  dofh_loadsz; } ;
typedef  TYPE_1__ dof_hdr_t ;

/* Variables and functions */
 int /*<<< orphan*/  kmem_free_aligned (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
dtrace_dof_destroy(dof_hdr_t *dof)
{
	kmem_free_aligned(dof, dof->dofh_loadsz);
}