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
typedef  int /*<<< orphan*/  nvlist_t ;

/* Variables and functions */
 int /*<<< orphan*/  DATA_TYPE_DOUBLE ; 
 int nvlist_add_common (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int,double*) ; 

int
nvlist_add_double(nvlist_t *nvl, const char *name, double val)
{
	return (nvlist_add_common(nvl, name, DATA_TYPE_DOUBLE, 1, &val));
}