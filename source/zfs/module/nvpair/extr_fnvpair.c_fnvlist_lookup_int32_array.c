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
typedef  int /*<<< orphan*/  uint_t ;
typedef  int /*<<< orphan*/  nvlist_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  VERIFY0 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvlist_lookup_int32_array (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

int32_t *
fnvlist_lookup_int32_array(nvlist_t *nvl, const char *name, uint_t *n)
{
	int32_t *rv;
	VERIFY0(nvlist_lookup_int32_array(nvl, name, &rv, n));
	return (rv);
}