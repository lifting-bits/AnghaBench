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
struct dsa_port {char const* name; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  DSA_PORT_TYPE_USER ; 

__attribute__((used)) static int dsa_port_parse_user(struct dsa_port *dp, const char *name)
{
	if (!name)
		name = "eth%d";

	dp->type = DSA_PORT_TYPE_USER;
	dp->name = name;

	return 0;
}