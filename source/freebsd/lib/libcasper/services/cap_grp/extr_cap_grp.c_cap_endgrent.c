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
typedef  int /*<<< orphan*/  cap_channel_t ;

/* Variables and functions */
 int /*<<< orphan*/  cap_xfer_nvlist (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nvlist_add_string (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/ * nvlist_create (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvlist_destroy (int /*<<< orphan*/ ) ; 

void
cap_endgrent(cap_channel_t *chan)
{
	nvlist_t *nvl;

	nvl = nvlist_create(0);
	nvlist_add_string(nvl, "cmd", "endgrent");
	/* Ignore any errors, we have no way to report them. */
	nvlist_destroy(cap_xfer_nvlist(chan, nvl));
}