#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_6__ {int /*<<< orphan*/  UseEncrypt; } ;
struct TYPE_5__ {int /*<<< orphan*/  Sock; } ;
typedef  TYPE_1__ TCPSOCK ;
typedef  TYPE_2__ SESSION ;

/* Variables and functions */
 int /*<<< orphan*/  Send (int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

UINT TcpSockSend(SESSION *s, TCPSOCK *ts, void *data, UINT size)
{
	// Transmission
	return Send(ts->Sock, data, size, s->UseEncrypt);
}