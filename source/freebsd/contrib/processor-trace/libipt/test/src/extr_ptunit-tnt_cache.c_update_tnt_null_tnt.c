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
struct pt_packet_tnt {int dummy; } ;

/* Variables and functions */
 int pt_tnt_cache_update_tnt (int /*<<< orphan*/ *,struct pt_packet_tnt*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pte_invalid ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result update_tnt_null_tnt(void)
{
	struct pt_packet_tnt packet;
	int errcode;

	errcode = pt_tnt_cache_update_tnt(NULL, &packet, NULL);
	ptu_int_eq(errcode, -pte_invalid);

	return ptu_passed();
}