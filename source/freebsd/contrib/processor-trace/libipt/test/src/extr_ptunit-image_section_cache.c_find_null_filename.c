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
struct ptunit_result {int dummy; } ;
struct iscache_fixture {int /*<<< orphan*/  iscache; } ;

/* Variables and functions */
 int pt_iscache_find (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned long long,unsigned long long,unsigned long long) ; 
 int /*<<< orphan*/  pte_internal ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result find_null_filename(struct iscache_fixture *cfix)
{
	int errcode;

	errcode = pt_iscache_find(&cfix->iscache, NULL, 0ull, 0ull, 0ull);
	ptu_int_eq(errcode, -pte_internal);

	return ptu_passed();
}