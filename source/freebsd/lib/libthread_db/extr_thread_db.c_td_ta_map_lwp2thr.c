#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  td_thrhandle_t ;
struct TYPE_6__ {TYPE_1__* ta_ops; } ;
typedef  TYPE_2__ td_thragent_t ;
typedef  int /*<<< orphan*/  td_err_e ;
typedef  int /*<<< orphan*/  lwpid_t ;
struct TYPE_5__ {int /*<<< orphan*/  (* to_ta_map_lwp2thr ) (TYPE_2__ const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_2__ const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

td_err_e
td_ta_map_lwp2thr(const td_thragent_t *ta, lwpid_t lwpid, td_thrhandle_t *th)
{
	return (ta->ta_ops->to_ta_map_lwp2thr(ta, lwpid, th));
}