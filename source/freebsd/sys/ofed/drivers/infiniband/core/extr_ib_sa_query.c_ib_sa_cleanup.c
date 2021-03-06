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

/* Variables and functions */
 int /*<<< orphan*/  ib_unregister_client (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  idr_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mcast_cleanup () ; 
 int /*<<< orphan*/  query_idr ; 
 int /*<<< orphan*/  sa_client ; 

void ib_sa_cleanup(void)
{
	mcast_cleanup();
	ib_unregister_client(&sa_client);
	idr_destroy(&query_idr);
}