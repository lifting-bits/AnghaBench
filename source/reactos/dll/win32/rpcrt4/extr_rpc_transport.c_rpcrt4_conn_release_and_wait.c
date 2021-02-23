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
struct TYPE_4__ {int ref; int /*<<< orphan*/ * wait_release; } ;
typedef  TYPE_1__ RpcConnection ;
typedef  int /*<<< orphan*/ * HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CreateEventW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  INFINITE ; 
 int /*<<< orphan*/  RPCRT4_ReleaseConnection (TYPE_1__*) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  WaitForSingleObject (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void rpcrt4_conn_release_and_wait(RpcConnection *connection)
{
    HANDLE event = NULL;

    if (connection->ref > 1)
        event = connection->wait_release = CreateEventW(NULL, TRUE, FALSE, NULL);

    RPCRT4_ReleaseConnection(connection);

    if(event)
    {
        WaitForSingleObject(event, INFINITE);
        CloseHandle(event);
    }
}