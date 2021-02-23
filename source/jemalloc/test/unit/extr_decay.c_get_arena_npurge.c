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
typedef  scalar_t__ uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  do_epoch () ; 
 scalar_t__ get_arena_npurge_impl (char*,unsigned int) ; 

__attribute__((used)) static uint64_t
get_arena_npurge(unsigned arena_ind) {
	do_epoch();
	return get_arena_npurge_impl("stats.arenas.0.dirty_npurge", arena_ind) +
	    get_arena_npurge_impl("stats.arenas.0.muzzy_npurge", arena_ind);
}