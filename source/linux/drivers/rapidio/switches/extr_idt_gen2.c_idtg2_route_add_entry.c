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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct rio_mport {int dummy; } ;

/* Variables and functions */
 scalar_t__ IDT_DEFAULT_ROUTE ; 
 int /*<<< orphan*/  LOCAL_RTE_CONF_DESTID_SEL ; 
 scalar_t__ RIO_GLOBAL_TABLE ; 
 scalar_t__ RIO_INVALID_ROUTE ; 
 int /*<<< orphan*/  RIO_STD_RTE_CONF_DESTID_SEL_CSR ; 
 int /*<<< orphan*/  RIO_STD_RTE_CONF_PORT_SEL_CSR ; 
 int /*<<< orphan*/  rio_mport_write_config_32 (struct rio_mport*,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int
idtg2_route_add_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
		       u16 table, u16 route_destid, u8 route_port)
{
	/*
	 * Select routing table to update
	 */
	if (table == RIO_GLOBAL_TABLE)
		table = 0;
	else
		table++;

	if (route_port == RIO_INVALID_ROUTE)
		route_port = IDT_DEFAULT_ROUTE;

	rio_mport_write_config_32(mport, destid, hopcount,
				  LOCAL_RTE_CONF_DESTID_SEL, table);

	/*
	 * Program destination port for the specified destID
	 */
	rio_mport_write_config_32(mport, destid, hopcount,
				  RIO_STD_RTE_CONF_DESTID_SEL_CSR,
				  (u32)route_destid);

	rio_mport_write_config_32(mport, destid, hopcount,
				  RIO_STD_RTE_CONF_PORT_SEL_CSR,
				  (u32)route_port);
	udelay(10);

	return 0;
}