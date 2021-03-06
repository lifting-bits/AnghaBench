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
 int /*<<< orphan*/  MTX_DEF ; 
 int /*<<< orphan*/  M_DQUOT ; 
 int /*<<< orphan*/  TAILQ_INIT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  desiredvnodes ; 
 int /*<<< orphan*/  dqfreelist ; 
 int /*<<< orphan*/  dqhash ; 
 int /*<<< orphan*/  dqhashtbl ; 
 int /*<<< orphan*/  dqhlock ; 
 int /*<<< orphan*/  hashinit (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_init (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void
dqinit(void)
{

	mtx_init(&dqhlock, "dqhlock", NULL, MTX_DEF);
	dqhashtbl = hashinit(desiredvnodes, M_DQUOT, &dqhash);
	TAILQ_INIT(&dqfreelist);
}