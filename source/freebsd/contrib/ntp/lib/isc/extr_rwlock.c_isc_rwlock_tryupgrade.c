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
struct TYPE_4__ {scalar_t__ type; int active; } ;
typedef  TYPE_1__ isc_rwlock_t ;
typedef  int /*<<< orphan*/  isc_result_t ;

/* Variables and functions */
 int /*<<< orphan*/  ISC_R_LOCKBUSY ; 
 int /*<<< orphan*/  ISC_R_SUCCESS ; 
 int /*<<< orphan*/  REQUIRE (int) ; 
 int VALID_RWLOCK (TYPE_1__*) ; 
 scalar_t__ isc_rwlocktype_read ; 
 scalar_t__ isc_rwlocktype_write ; 

isc_result_t
isc_rwlock_tryupgrade(isc_rwlock_t *rwl) {
	isc_result_t result = ISC_R_SUCCESS;

	REQUIRE(VALID_RWLOCK(rwl));
	REQUIRE(rwl->type == isc_rwlocktype_read);
	REQUIRE(rwl->active != 0);

	/* If we are the only reader then succeed. */
	if (rwl->active == 1)
		rwl->type = isc_rwlocktype_write;
	else
		result = ISC_R_LOCKBUSY;
	return (result);
}