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
typedef  int /*<<< orphan*/  tGATT_TCB ;
typedef  int /*<<< orphan*/  UINT16 ;
typedef  int /*<<< orphan*/  BT_HDR ;

/* Variables and functions */
 scalar_t__ GATT_CH_OPEN ; 
 int /*<<< orphan*/  gatt_data_process (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * gatt_find_tcb_by_cid (int /*<<< orphan*/ ) ; 
 scalar_t__ gatt_get_ch_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  osi_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void gatt_l2cif_data_ind_cback(UINT16 lcid, BT_HDR *p_buf)
{
    tGATT_TCB       *p_tcb;

    /* look up clcb for this channel */
    if ((p_tcb = gatt_find_tcb_by_cid(lcid)) != NULL &&
            gatt_get_ch_state(p_tcb) == GATT_CH_OPEN) {
        /* process the data */
        gatt_data_process(p_tcb, p_buf);
    } else { /* prevent buffer leak */
        osi_free(p_buf);
    }

}