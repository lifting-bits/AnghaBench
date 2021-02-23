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
struct nn_sws {int /*<<< orphan*/  fsm; int /*<<< orphan*/  handshaker; int /*<<< orphan*/  pipebase; int /*<<< orphan*/  inmsg_array; int /*<<< orphan*/  outmsg; int /*<<< orphan*/  done; } ;

/* Variables and functions */
 int /*<<< orphan*/  NN_SWS_STATE_IDLE ; 
 int /*<<< orphan*/  nn_assert_state (struct nn_sws*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nn_fsm_event_term (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_fsm_term (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_msg_array_term (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_msg_term (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_pipebase_term (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nn_ws_handshake_term (int /*<<< orphan*/ *) ; 

void nn_sws_term (struct nn_sws *self)
{
    nn_assert_state (self, NN_SWS_STATE_IDLE);

    nn_fsm_event_term (&self->done);
    nn_msg_term (&self->outmsg);
    nn_msg_array_term (&self->inmsg_array);
    nn_pipebase_term (&self->pipebase);
    nn_ws_handshake_term (&self->handshaker);
    nn_fsm_term (&self->fsm);
}