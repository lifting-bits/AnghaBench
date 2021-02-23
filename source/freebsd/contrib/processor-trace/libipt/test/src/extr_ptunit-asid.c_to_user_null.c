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
struct pt_asid {int dummy; } ;
typedef  int /*<<< orphan*/  asid ;

/* Variables and functions */
 int /*<<< orphan*/  pt_asid_init (struct pt_asid*) ; 
 int pt_asid_to_user (int /*<<< orphan*/ *,struct pt_asid*,int) ; 
 int /*<<< orphan*/  pte_internal ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result to_user_null(void)
{
	struct pt_asid asid;
	int errcode;

	pt_asid_init(&asid);

	errcode = pt_asid_to_user(NULL, NULL, sizeof(asid));
	ptu_int_eq(errcode, -pte_internal);

	errcode = pt_asid_to_user(NULL, &asid, sizeof(asid));
	ptu_int_eq(errcode, -pte_internal);

	return ptu_passed();
}