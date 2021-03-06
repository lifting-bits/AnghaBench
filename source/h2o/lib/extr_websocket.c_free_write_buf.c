#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {size_t cnt; TYPE_1__* bufs; } ;
struct TYPE_7__ {TYPE_2__ _write_buf; } ;
typedef  TYPE_3__ h2o_websocket_conn_t ;
struct TYPE_5__ {int /*<<< orphan*/  base; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void free_write_buf(h2o_websocket_conn_t *conn)
{
    size_t i;
    for (i = 0; i < conn->_write_buf.cnt; ++i)
        free(conn->_write_buf.bufs[i].base);
}