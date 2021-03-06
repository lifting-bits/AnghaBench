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
struct kobject {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ppi_attr_grp ; 
 int sysfs_create_group (struct kobject*,int /*<<< orphan*/ *) ; 

int tpm_add_ppi(struct kobject *parent)
{
	return sysfs_create_group(parent, &ppi_attr_grp);
}