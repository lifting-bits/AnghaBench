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
struct llentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LLE_WUNLOCK (struct llentry*) ; 
 int /*<<< orphan*/  in_lltable_destroy_lle_unlocked (struct llentry*) ; 

__attribute__((used)) static void
in_lltable_destroy_lle(struct llentry *lle)
{
	LLE_WUNLOCK(lle);
	in_lltable_destroy_lle_unlocked(lle);
}