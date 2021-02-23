#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  generated_endpoint ;
typedef  int ULONG ;
struct TYPE_9__ {TYPE_1__* protseq; int /*<<< orphan*/  protseq_entry; int /*<<< orphan*/  Endpoint; } ;
struct TYPE_8__ {void* listen_pipe; } ;
struct TYPE_7__ {int /*<<< orphan*/  cs; int /*<<< orphan*/  listeners; int /*<<< orphan*/  Protseq; } ;
typedef  TYPE_1__ RpcServerProtseq ;
typedef  TYPE_2__ RpcConnection_np ;
typedef  TYPE_3__ RpcConnection ;
typedef  scalar_t__ RPC_STATUS ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  EnterCriticalSection (int /*<<< orphan*/ *) ; 
 int GetCurrentProcessId () ; 
 int InterlockedExchangeAdd (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  LeaveCriticalSection (int /*<<< orphan*/ *) ; 
 scalar_t__ RPCRT4_CreateConnection (TYPE_3__**,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ RPC_S_OK ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  list_add_head (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* ncacn_pipe_name (int /*<<< orphan*/ ,...) ; 
 scalar_t__ rpcrt4_conn_create_pipe (TYPE_3__*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int) ; 

__attribute__((used)) static RPC_STATUS rpcrt4_protseq_ncacn_np_open_endpoint(RpcServerProtseq *protseq, const char *endpoint)
{
  RPC_STATUS r;
  RpcConnection *Connection;
  char generated_endpoint[26];

  if (!endpoint)
  {
    static LONG np_nameless_id;
    DWORD process_id = GetCurrentProcessId();
    ULONG id = InterlockedExchangeAdd(&np_nameless_id, 1 );
    snprintf(generated_endpoint, sizeof(generated_endpoint),
             "\\\\pipe\\\\%08x.%03x", process_id, id);
    endpoint = generated_endpoint;
  }

  r = RPCRT4_CreateConnection(&Connection, TRUE, protseq->Protseq, NULL,
                              endpoint, NULL, NULL, NULL, NULL);
  if (r != RPC_S_OK)
    return r;

#ifdef __REACTOS__
  ((RpcConnection_np*)Connection)->listen_pipe = ncacn_pipe_name(NULL, Connection->Endpoint);
#else
  ((RpcConnection_np*)Connection)->listen_pipe = ncacn_pipe_name(Connection->Endpoint);
#endif
  r = rpcrt4_conn_create_pipe(Connection);

  EnterCriticalSection(&protseq->cs);
  list_add_head(&protseq->listeners, &Connection->protseq_entry);
  Connection->protseq = protseq;
  LeaveCriticalSection(&protseq->cs);

  return r;
}