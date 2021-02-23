#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct qeth_cmd_buffer {int /*<<< orphan*/  data; } ;
struct TYPE_2__ {int /*<<< orphan*/  cm_filter_r; int /*<<< orphan*/  cm_connection_w; int /*<<< orphan*/  issuer_rm_r; } ;
struct qeth_card {TYPE_1__ token; int /*<<< orphan*/  write; } ;

/* Variables and functions */
 int /*<<< orphan*/ * CM_SETUP ; 
 int /*<<< orphan*/  CM_SETUP_SIZE ; 
 int /*<<< orphan*/  QETH_CM_SETUP_CONNECTION_TOKEN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QETH_CM_SETUP_DEST_ADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QETH_CM_SETUP_FILTER_TOKEN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QETH_DBF_TEXT (int /*<<< orphan*/ ,int,char*) ; 
 int /*<<< orphan*/  QETH_MPC_TOKEN_LENGTH ; 
 int /*<<< orphan*/  SETUP ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qeth_cm_setup_cb ; 
 int qeth_send_control_data (struct qeth_card*,int /*<<< orphan*/ ,struct qeth_cmd_buffer*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct qeth_cmd_buffer* qeth_wait_for_buffer (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int qeth_cm_setup(struct qeth_card *card)
{
	int rc;
	struct qeth_cmd_buffer *iob;

	QETH_DBF_TEXT(SETUP, 2, "cmsetup");

	iob = qeth_wait_for_buffer(&card->write);
	memcpy(iob->data, CM_SETUP, CM_SETUP_SIZE);
	memcpy(QETH_CM_SETUP_DEST_ADDR(iob->data),
	       &card->token.issuer_rm_r, QETH_MPC_TOKEN_LENGTH);
	memcpy(QETH_CM_SETUP_CONNECTION_TOKEN(iob->data),
	       &card->token.cm_connection_w, QETH_MPC_TOKEN_LENGTH);
	memcpy(QETH_CM_SETUP_FILTER_TOKEN(iob->data),
	       &card->token.cm_filter_r, QETH_MPC_TOKEN_LENGTH);
	rc = qeth_send_control_data(card, CM_SETUP_SIZE, iob,
				    qeth_cm_setup_cb, NULL);
	return rc;

}