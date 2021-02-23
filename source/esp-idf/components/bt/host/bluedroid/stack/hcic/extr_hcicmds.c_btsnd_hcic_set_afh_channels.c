#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT8 ;
struct TYPE_4__ {scalar_t__ offset; scalar_t__ len; } ;
typedef  TYPE_1__ BT_HDR ;
typedef  int /*<<< orphan*/  BOOLEAN ;
typedef  int /*<<< orphan*/  AFH_CHANNELS ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_TO_STREAM (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ HCIC_PARAM_SIZE_SET_AFH_CHANNELS ; 
 scalar_t__ HCIC_PREAMBLE_SIZE ; 
 TYPE_1__* HCI_GET_CMD_BUF (scalar_t__) ; 
 int /*<<< orphan*/  HCI_SET_AFH_CHANNELS ; 
 int /*<<< orphan*/  LOCAL_BR_EDR_CONTROLLER_ID ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UINT16_TO_STREAM (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UINT8_TO_STREAM (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  btu_hcif_send_cmd (int /*<<< orphan*/ ,TYPE_1__*) ; 

BOOLEAN btsnd_hcic_set_afh_channels (AFH_CHANNELS channels)
{
    BT_HDR *p;
    UINT8 *pp;

    if ((p = HCI_GET_CMD_BUF(HCIC_PARAM_SIZE_SET_AFH_CHANNELS)) == NULL) {
        return (FALSE);
    }

    pp = (UINT8 *)(p + 1);

    p->len    = HCIC_PREAMBLE_SIZE + HCIC_PARAM_SIZE_SET_AFH_CHANNELS;
    p->offset = 0;

    UINT16_TO_STREAM (pp, HCI_SET_AFH_CHANNELS);
    UINT8_TO_STREAM  (pp, HCIC_PARAM_SIZE_SET_AFH_CHANNELS);

    ARRAY_TO_STREAM  (pp, channels, HCIC_PARAM_SIZE_SET_AFH_CHANNELS);

    btu_hcif_send_cmd (LOCAL_BR_EDR_CONTROLLER_ID,  p);
    return (TRUE);
}