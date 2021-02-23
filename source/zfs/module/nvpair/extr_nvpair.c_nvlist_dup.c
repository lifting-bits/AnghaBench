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
 int /*<<< orphan*/  nvlist_nv_alloc (int) ; 
 int nvlist_xdup (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

int
nvlist_dup(nvlist_t *nvl, nvlist_t **nvlp, int kmflag)
{
	return (nvlist_xdup(nvl, nvlp, nvlist_nv_alloc(kmflag)));
}