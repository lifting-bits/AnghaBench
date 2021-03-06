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
typedef  int /*<<< orphan*/  u8 ;
struct acpi_ec {int /*<<< orphan*/  timestamp; int /*<<< orphan*/  command_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  ec_dbg_raw (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jiffies ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void acpi_ec_write_cmd(struct acpi_ec *ec, u8 command)
{
	ec_dbg_raw("EC_SC(W) = 0x%2.2x", command);
	outb(command, ec->command_addr);
	ec->timestamp = jiffies;
}