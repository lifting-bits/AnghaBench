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
struct TYPE_3__ {int /*<<< orphan*/  rl_longholds; } ;
typedef  TYPE_1__ redaction_list_t ;

/* Variables and functions */
 int /*<<< orphan*/  zfs_refcount_remove (int /*<<< orphan*/ *,void*) ; 

void
dsl_redaction_list_long_rele(redaction_list_t *rl, void *tag)
{
	(void) zfs_refcount_remove(&rl->rl_longholds, tag);
}