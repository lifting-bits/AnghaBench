#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * fl_ops; } ;
struct TYPE_5__ {TYPE_1__ fl; } ;
struct TYPE_6__ {TYPE_2__ lock; } ;
struct nlm_rqst {TYPE_3__ a_args; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nlmclnt_release_lockargs(struct nlm_rqst *req)
{
	BUG_ON(req->a_args.lock.fl.fl_ops != NULL);
}