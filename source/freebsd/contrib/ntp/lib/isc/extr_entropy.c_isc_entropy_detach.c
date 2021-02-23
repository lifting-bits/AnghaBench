#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ refcnt; int /*<<< orphan*/  lock; } ;
typedef  TYPE_1__ isc_entropy_t ;
typedef  scalar_t__ isc_boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  LOCK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  REQUIRE (int) ; 
 int /*<<< orphan*/  UNLOCK (int /*<<< orphan*/ *) ; 
 scalar_t__ VALID_ENTROPY (TYPE_1__*) ; 
 int /*<<< orphan*/  destroy (TYPE_1__**) ; 
 scalar_t__ destroy_check (TYPE_1__*) ; 

void
isc_entropy_detach(isc_entropy_t **entp) {
	isc_entropy_t *ent;
	isc_boolean_t killit;

	REQUIRE(entp != NULL && VALID_ENTROPY(*entp));
	ent = *entp;
	*entp = NULL;

	LOCK(&ent->lock);

	REQUIRE(ent->refcnt > 0);
	ent->refcnt--;

	killit = destroy_check(ent);

	UNLOCK(&ent->lock);

	if (killit)
		destroy(&ent);
}