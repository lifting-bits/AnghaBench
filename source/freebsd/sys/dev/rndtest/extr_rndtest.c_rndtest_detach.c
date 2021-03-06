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
struct rndtest_state {int /*<<< orphan*/  rs_to; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_DEVBUF ; 
 int /*<<< orphan*/  callout_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (struct rndtest_state*,int /*<<< orphan*/ ) ; 

void
rndtest_detach(struct rndtest_state *rsp)
{
	callout_stop(&rsp->rs_to);
	free(rsp, M_DEVBUF);
}