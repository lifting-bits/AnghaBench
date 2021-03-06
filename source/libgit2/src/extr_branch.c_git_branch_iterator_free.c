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
typedef  int /*<<< orphan*/  git_branch_iterator ;
struct TYPE_3__ {int /*<<< orphan*/  iter; } ;
typedef  TYPE_1__ branch_iter ;

/* Variables and functions */
 int /*<<< orphan*/  git__free (TYPE_1__*) ; 
 int /*<<< orphan*/  git_reference_iterator_free (int /*<<< orphan*/ ) ; 

void git_branch_iterator_free(git_branch_iterator *_iter)
{
	branch_iter *iter = (branch_iter *) _iter;

	if (iter == NULL)
		return;

	git_reference_iterator_free(iter->iter);
	git__free(iter);
}