#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  err_t ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_9__ {int /*<<< orphan*/  Lock; int /*<<< orphan*/  ConnectRequest; } ;
struct TYPE_8__ {scalar_t__ Information; int /*<<< orphan*/  Status; } ;
typedef  TYPE_1__* PTDI_BUCKET ;
typedef  int /*<<< orphan*/  PLIST_ENTRY ;
typedef  TYPE_2__* PCONNECTION_ENDPOINT ;

/* Variables and functions */
 TYPE_1__* CONTAINING_RECORD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CompleteBucket (TYPE_2__*,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DereferenceObject (TYPE_2__*) ; 
 int /*<<< orphan*/  ExInterlockedRemoveHeadList (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  ReferenceObject (TYPE_2__*) ; 
 int /*<<< orphan*/  TCPTranslateError (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  TDI_BUCKET ; 

VOID
TCPConnectEventHandler(void *arg, const err_t err)
{
    PCONNECTION_ENDPOINT Connection = (PCONNECTION_ENDPOINT)arg;
    PTDI_BUCKET Bucket;
    PLIST_ENTRY Entry;
        
    ReferenceObject(Connection);
    
    while ((Entry = ExInterlockedRemoveHeadList(&Connection->ConnectRequest, &Connection->Lock)))
    {
        
        Bucket = CONTAINING_RECORD( Entry, TDI_BUCKET, Entry );
        
        Bucket->Status = TCPTranslateError(err);
        Bucket->Information = 0;
                
        CompleteBucket(Connection, Bucket, FALSE);
    }
    
    DereferenceObject(Connection);
}