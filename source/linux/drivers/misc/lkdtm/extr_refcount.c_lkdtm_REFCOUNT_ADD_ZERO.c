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
typedef  int /*<<< orphan*/  refcount_t ;

/* Variables and functions */
 int /*<<< orphan*/  REFCOUNT_INIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  check_from_zero (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  refcount_add (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_add_not_zero (int,int /*<<< orphan*/ *) ; 
 scalar_t__ refcount_read (int /*<<< orphan*/ *) ; 

void lkdtm_REFCOUNT_ADD_ZERO(void)
{
	refcount_t zero = REFCOUNT_INIT(0);

	pr_info("attempting safe refcount_add_not_zero() from zero\n");
	if (!refcount_add_not_zero(3, &zero)) {
		pr_info("Good: zero detected\n");
		if (refcount_read(&zero) == 0)
			pr_info("Correctly stayed at zero\n");
		else
			pr_err("Fail: refcount went past zero\n");
	} else {
		pr_err("Fail: Zero not detected!?\n");
	}

	pr_info("attempting bad refcount_add() from zero\n");
	refcount_add(3, &zero);

	check_from_zero(&zero);
}