#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/ * ops; } ;
typedef  TYPE_1__ Connection ;

/* Variables and functions */
 int /*<<< orphan*/  pfree (TYPE_1__*) ; 
 int /*<<< orphan*/  ts_connection_close (TYPE_1__*) ; 

void
ts_connection_destroy(Connection *conn)
{
	if (conn == NULL)
		return;

	ts_connection_close(conn);
	conn->ops = NULL;
	pfree(conn);
}