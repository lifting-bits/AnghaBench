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
typedef  int /*<<< orphan*/  u_char ;
struct l3_process {int /*<<< orphan*/  timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  CC_T302 ; 
 int /*<<< orphan*/  L3AddTimer (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  L3DelTimer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MT_SETUP_ACKNOWLEDGE ; 
 int /*<<< orphan*/  T302 ; 
 int /*<<< orphan*/  l3dss1_message (struct l3_process*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  newl3state (struct l3_process*,int) ; 

__attribute__((used)) static void
l3dss1_setup_ack_req(struct l3_process *pc, u_char pr,
		   void *arg)
{
	newl3state(pc, 25);
	L3DelTimer(&pc->timer);
	L3AddTimer(&pc->timer, T302, CC_T302);
	l3dss1_message(pc, MT_SETUP_ACKNOWLEDGE);
}