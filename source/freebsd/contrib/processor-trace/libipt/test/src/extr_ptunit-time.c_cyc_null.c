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
struct time_fixture {int /*<<< orphan*/  time; int /*<<< orphan*/  config; } ;
struct ptunit_result {int dummy; } ;
struct pt_packet_cyc {int dummy; } ;

/* Variables and functions */
 int pt_time_update_cyc (int /*<<< orphan*/ *,struct pt_packet_cyc*,int /*<<< orphan*/ *,unsigned long long) ; 
 int /*<<< orphan*/  pte_internal ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result cyc_null(struct time_fixture *tfix)
{
	struct pt_packet_cyc packet;
	int errcode;

	errcode = pt_time_update_cyc(NULL, &packet, &tfix->config, 0ull);
	ptu_int_eq(errcode, -pte_internal);

	errcode = pt_time_update_cyc(&tfix->time, NULL, &tfix->config, 0ull);
	ptu_int_eq(errcode, -pte_internal);

	errcode = pt_time_update_cyc(&tfix->time, &packet, NULL, 0ull);
	ptu_int_eq(errcode, -pte_internal);

	return ptu_passed();
}