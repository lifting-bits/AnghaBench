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
struct vlc_h2_frame {int dummy; } ;
struct vlc_h2_conn {int /*<<< orphan*/  out; int /*<<< orphan*/  opaque; } ;

/* Variables and functions */
 int /*<<< orphan*/  vlc_h2_frame_dump (int /*<<< orphan*/ ,struct vlc_h2_frame*,char*) ; 
 int vlc_h2_output_send_prio (int /*<<< orphan*/ ,struct vlc_h2_frame*) ; 

__attribute__((used)) static int vlc_h2_conn_queue_prio(struct vlc_h2_conn *conn,
                                  struct vlc_h2_frame *f)
{
    vlc_h2_frame_dump(conn->opaque, f, "out (priority)");
    return vlc_h2_output_send_prio(conn->out, f);
}