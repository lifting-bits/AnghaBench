#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct st_quicly_handle_payload_state_t {int /*<<< orphan*/  end; int /*<<< orphan*/  src; } ;
typedef  int /*<<< orphan*/  quicly_conn_t ;
struct TYPE_5__ {int /*<<< orphan*/  len; int /*<<< orphan*/  base; } ;
struct TYPE_4__ {TYPE_3__ reason_phrase; int /*<<< orphan*/  error_code; } ;
typedef  TYPE_1__ quicly_application_close_frame_t ;

/* Variables and functions */
 int /*<<< orphan*/  APPLICATION_CLOSE_RECEIVE ; 
 int /*<<< orphan*/  QUICLY_ERROR_FROM_APPLICATION_ERROR_CODE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QUICLY_PROBE (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QUICLY_PROBE_ESCAPE_UNSAFE_STRING (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UINT64_MAX ; 
 int handle_close (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__) ; 
 int /*<<< orphan*/  probe_now () ; 
 int quicly_decode_application_close_frame (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 

__attribute__((used)) static int handle_application_close_frame(quicly_conn_t *conn, struct st_quicly_handle_payload_state_t *state)
{
    quicly_application_close_frame_t frame;
    int ret;

    if ((ret = quicly_decode_application_close_frame(&state->src, state->end, &frame)) != 0)
        return ret;

    QUICLY_PROBE(APPLICATION_CLOSE_RECEIVE, conn, probe_now(), frame.error_code,
                 QUICLY_PROBE_ESCAPE_UNSAFE_STRING(frame.reason_phrase.base, frame.reason_phrase.len));
    return handle_close(conn, QUICLY_ERROR_FROM_APPLICATION_ERROR_CODE(frame.error_code), UINT64_MAX, frame.reason_phrase);
}