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
struct TYPE_4__ {int /*<<< orphan*/  index; int /*<<< orphan*/  snap; } ;
typedef  TYPE_1__ git_index_iterator ;

/* Variables and functions */
 int /*<<< orphan*/  git__free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_index_snapshot_release (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void git_index_iterator_free(git_index_iterator *it)
{
	if (it == NULL)
		return;

	git_index_snapshot_release(&it->snap, it->index);
	git__free(it);
}