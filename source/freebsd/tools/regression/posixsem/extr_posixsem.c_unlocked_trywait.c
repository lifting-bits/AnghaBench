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
typedef  int /*<<< orphan*/  semid_t ;

/* Variables and functions */
 scalar_t__ checkvalue (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fail_errno (char*) ; 
 scalar_t__ ksem_destroy (int /*<<< orphan*/ ) ; 
 scalar_t__ ksem_init (int /*<<< orphan*/ *,int) ; 
 scalar_t__ ksem_trywait (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pass () ; 

__attribute__((used)) static void
unlocked_trywait(void)
{
	semid_t id;

	if (ksem_init(&id, 1) < 0) {
		fail_errno("ksem_init");
		return;
	}

	/* This should succeed and decrement the value to 0. */
	if (ksem_trywait(id) < 0) {
		fail_errno("ksem_trywait()");
		ksem_destroy(id);
		return;
	}
	if (checkvalue(id, 0) < 0) {
		ksem_destroy(id);
		return;
	}

	if (ksem_destroy(id) < 0) {
		fail_errno("ksem_destroy");
		return;
	}
	pass();
}