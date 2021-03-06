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
struct bnx2x_credit_pool_obj {int /*<<< orphan*/  credit; } ;

/* Variables and functions */
 int __atomic_dec_ifmoe (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_mb () ; 

__attribute__((used)) static bool bnx2x_credit_pool_get(struct bnx2x_credit_pool_obj *o, int cnt)
{
	bool rc;

	smp_mb();
	rc = __atomic_dec_ifmoe(&o->credit, cnt, 0);
	smp_mb();

	return rc;
}