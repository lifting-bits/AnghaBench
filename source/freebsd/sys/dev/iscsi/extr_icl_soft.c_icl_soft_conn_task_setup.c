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
typedef  int /*<<< orphan*/  uint32_t ;
struct icl_pdu {int dummy; } ;
struct icl_conn {int dummy; } ;
struct ccb_scsiio {int dummy; } ;

/* Variables and functions */

int
icl_soft_conn_task_setup(struct icl_conn *ic, struct icl_pdu *ip,
    struct ccb_scsiio *csio, uint32_t *task_tagp, void **prvp)
{

	return (0);
}