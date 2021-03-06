#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct apply_state {TYPE_1__* repo; scalar_t__ index_file; } ;
struct TYPE_2__ {int /*<<< orphan*/  index; } ;

/* Variables and functions */
 int /*<<< orphan*/  get_git_dir () ; 
 int read_index_from (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int repo_read_index (TYPE_1__*) ; 

__attribute__((used)) static int read_apply_cache(struct apply_state *state)
{
	if (state->index_file)
		return read_index_from(state->repo->index, state->index_file,
				       get_git_dir());
	else
		return repo_read_index(state->repo);
}