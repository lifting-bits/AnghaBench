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
struct TYPE_4__ {int HaltFlag; int /*<<< orphan*/  HaltEvent; int /*<<< orphan*/  Thread; } ;
typedef  TYPE_1__ UPDATE_CLIENT ;

/* Variables and functions */
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 int /*<<< orphan*/  INFINITE ; 
 int /*<<< orphan*/  ReleaseEvent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ReleaseThread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Set (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WaitThread (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void FreeUpdateClient(UPDATE_CLIENT *c)
{
	// Validate arguments
	if (c == NULL)
	{
		return;
	}

	// Thread stop
	c->HaltFlag = true;
	Set(c->HaltEvent);

	// Wait for thread termination
	WaitThread(c->Thread, INFINITE);

	ReleaseThread(c->Thread);
	ReleaseEvent(c->HaltEvent);

	Free(c);
}