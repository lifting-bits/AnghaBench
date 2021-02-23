#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  ref; int /*<<< orphan*/  Name; } ;
typedef  TYPE_2__ USER ;
struct TYPE_11__ {TYPE_1__* HubDb; } ;
struct TYPE_9__ {int /*<<< orphan*/  UserList; } ;
typedef  TYPE_3__ HUB ;

/* Variables and functions */
 int AcIsUser (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AddRef (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Insert (int /*<<< orphan*/ ,TYPE_2__*) ; 
 scalar_t__ LIST_NUM (int /*<<< orphan*/ ) ; 
 scalar_t__ MAX_USERS ; 
 scalar_t__ NO_ACCOUNT_DB (TYPE_3__*) ; 

bool AcAddUser(HUB *h, USER *u)
{
	// Validate arguments
	if (h == NULL || u == NULL || NO_ACCOUNT_DB(h))
	{
		return false;
	}

	if (LIST_NUM(h->HubDb->UserList) >= MAX_USERS)
	{
		return false;
	}

	if (AcIsUser(h, u->Name) != false)
	{
		return false;
	}

	Insert(h->HubDb->UserList, u);
	AddRef(u->ref);

	return true;
}