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
typedef  int /*<<< orphan*/  swir ;
struct sa_handle {int dummy; } ;
struct query_params {int dummy; } ;
struct query_cmd {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  lid; } ;
typedef  TYPE_1__ ib_switch_info_record_t ;
typedef  int /*<<< orphan*/  ib_net64_t ;

/* Variables and functions */
 int /*<<< orphan*/  CHECK_AND_SET_VAL (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IB_SA_ATTR_SWITCHINFORECORD ; 
 int /*<<< orphan*/  LID ; 
 int /*<<< orphan*/  SWIR ; 
 int /*<<< orphan*/  dump_switch_info_record ; 
 int get_and_dump_any_records (struct sa_handle*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*,int,int /*<<< orphan*/ ,struct query_params*) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  parse_lid_and_ports (struct sa_handle*,char*,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int query_switchinfo_records(const struct query_cmd *q,
				struct sa_handle * h, struct query_params *p,
				int argc, char *argv[])
{
	ib_switch_info_record_t swir;
	ib_net64_t comp_mask = 0;
	int lid = 0;

	if (argc > 0)
		parse_lid_and_ports(h, argv[0], &lid, NULL, NULL);

	memset(&swir, 0, sizeof(swir));
	CHECK_AND_SET_VAL(lid, 16, 0, swir.lid, SWIR, LID);

	return get_and_dump_any_records(h, IB_SA_ATTR_SWITCHINFORECORD, 0,
					comp_mask, &swir, sizeof(swir),
					dump_switch_info_record, p);
}