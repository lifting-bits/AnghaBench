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
typedef  int /*<<< orphan*/  u16 ;
struct dsa_switch {int dummy; } ;

/* Variables and functions */
 int mv88e6123_61_65_port_to_phy_addr (int) ; 
 int mv88e6xxx_phy_write (struct dsa_switch*,int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mv88e6123_61_65_phy_write(struct dsa_switch *ds,
			      int port, int regnum, u16 val)
{
	int addr = mv88e6123_61_65_port_to_phy_addr(port);
	return mv88e6xxx_phy_write(ds, addr, regnum, val);
}