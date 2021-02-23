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
typedef  int /*<<< orphan*/  ipfw_obj_lheader ;

/* Variables and functions */
 int /*<<< orphan*/  IP_FW_TABLES_ALIST ; 
 int table_do_get_stdlist (int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 

__attribute__((used)) static int
table_do_get_algolist(ipfw_obj_lheader **polh)
{

	return (table_do_get_stdlist(IP_FW_TABLES_ALIST, polh));
}