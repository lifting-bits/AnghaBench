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
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  fail_errno (char*) ; 
 int /*<<< orphan*/  ksem_close_should_fail (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ksem_destroy (int /*<<< orphan*/ ) ; 
 scalar_t__ ksem_init (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void
close_unnamed_semaphore(void)
{
	semid_t id;

	if (ksem_init(&id, 1) < 0) {
		fail_errno("ksem_init");
		return;
	}

	ksem_close_should_fail(id, EINVAL);

	ksem_destroy(id);
}