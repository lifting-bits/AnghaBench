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
struct lio {int /*<<< orphan*/  ifstate; } ;

/* Variables and functions */
 int atomic_load_acq_int (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_store_rel_int (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline void
lio_ifstate_reset(struct lio *lio, int state_flag)
{

	atomic_store_rel_int(&lio->ifstate,
			     (atomic_load_acq_int(&lio->ifstate) &
			      ~(state_flag)));
}