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
struct isac {int dummy; } ;
struct FsmInst {struct isac* userdata; } ;

/* Variables and functions */
 int /*<<< orphan*/  D_L1L2 (struct isac*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FsmChangeState (struct FsmInst*,int /*<<< orphan*/ ) ; 
 int INDICATION ; 
 int PH_DEACTIVATE ; 
 int /*<<< orphan*/  ST_L1_F6 ; 

__attribute__((used)) static void l1_go_f6_deact_ind(struct FsmInst *fi, int event, void *arg)
{
	struct isac *isac = fi->userdata;

	FsmChangeState(fi, ST_L1_F6);
	D_L1L2(isac, PH_DEACTIVATE | INDICATION, NULL);
}