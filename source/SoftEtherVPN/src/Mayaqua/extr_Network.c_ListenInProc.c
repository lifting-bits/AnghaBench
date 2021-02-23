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
struct TYPE_4__ {int ListenMode; int Connected; int /*<<< orphan*/  InProcAcceptEvent; int /*<<< orphan*/  InProcAcceptQueue; int /*<<< orphan*/  Type; } ;
typedef  TYPE_1__ SOCK ;

/* Variables and functions */
 int /*<<< orphan*/  NewEvent () ; 
 int /*<<< orphan*/  NewQueue () ; 
 TYPE_1__* NewSock () ; 
 int /*<<< orphan*/  SOCK_INPROC ; 

SOCK *ListenInProc()
{
	SOCK *s = NewSock();

	s->Type = SOCK_INPROC;
	s->ListenMode = true;
	s->InProcAcceptQueue = NewQueue();
	s->InProcAcceptEvent = NewEvent();
	s->Connected = true;

	return s;
}