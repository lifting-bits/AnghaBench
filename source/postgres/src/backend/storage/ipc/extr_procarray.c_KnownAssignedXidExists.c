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
typedef  int /*<<< orphan*/  TransactionId ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int /*<<< orphan*/ ) ; 
 int KnownAssignedXidsSearch (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  TransactionIdIsValid (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
KnownAssignedXidExists(TransactionId xid)
{
	Assert(TransactionIdIsValid(xid));

	return KnownAssignedXidsSearch(xid, false);
}