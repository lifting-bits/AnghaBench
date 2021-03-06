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
struct TYPE_4__ {int /*<<< orphan*/  Sock; } ;
typedef  TYPE_1__ NOTIFY_CLIENT ;

/* Variables and functions */
 int /*<<< orphan*/  Disconnect (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 int /*<<< orphan*/  ReleaseSock (int /*<<< orphan*/ ) ; 

void CcDisconnectNotify(NOTIFY_CLIENT *n)
{
	// Validate arguments
	if (n == NULL)
	{
		return;
	}

	// Disconnect
	Disconnect(n->Sock);
	ReleaseSock(n->Sock);

	// Memory release
	Free(n);
}