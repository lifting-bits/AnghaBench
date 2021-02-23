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
struct qeth_card {int dummy; } ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */
 int /*<<< orphan*/  IPA_CMD_DELGMAC ; 
 int /*<<< orphan*/  QETH_DBF_TEXT (int /*<<< orphan*/ ,int,char*) ; 
 int /*<<< orphan*/  TRACE ; 
 int /*<<< orphan*/  qeth_l2_send_delgroupmac_cb ; 
 int qeth_l2_send_setdelmac (struct qeth_card*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int qeth_l2_send_delgroupmac(struct qeth_card *card, __u8 *mac)
{
	QETH_DBF_TEXT(TRACE, 2, "L2Dgmac");
	return qeth_l2_send_setdelmac(card, mac, IPA_CMD_DELGMAC,
					  qeth_l2_send_delgroupmac_cb);
}