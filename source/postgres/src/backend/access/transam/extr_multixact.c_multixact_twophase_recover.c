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
typedef  int uint32 ;
typedef  int /*<<< orphan*/  uint16 ;
typedef  int /*<<< orphan*/  TransactionId ;
typedef  int /*<<< orphan*/  MultiXactId ;
typedef  size_t BackendId ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 int /*<<< orphan*/ * OldestMemberMXactId ; 
 size_t TwoPhaseGetDummyBackendId (int /*<<< orphan*/ ,int) ; 

void
multixact_twophase_recover(TransactionId xid, uint16 info,
						   void *recdata, uint32 len)
{
	BackendId	dummyBackendId = TwoPhaseGetDummyBackendId(xid, false);
	MultiXactId oldestMember;

	/*
	 * Get the oldest member XID from the state file record, and set it in the
	 * OldestMemberMXactId slot reserved for this prepared transaction.
	 */
	Assert(len == sizeof(MultiXactId));
	oldestMember = *((MultiXactId *) recdata);

	OldestMemberMXactId[dummyBackendId] = oldestMember;
}