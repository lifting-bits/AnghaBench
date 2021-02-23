#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ pCallback; } ;
struct TYPE_4__ {TYPE_3__ InetTransport; } ;
typedef  TYPE_1__ POP3Transport ;
typedef  int /*<<< orphan*/  POP3RESPONSE ;
typedef  int /*<<< orphan*/  IPOP3Callback ;
typedef  int /*<<< orphan*/  IInternetTransport ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 scalar_t__ FAILED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IPOP3Callback_OnResponse (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InternetTransport_DropConnection (TYPE_3__*) ; 
 int /*<<< orphan*/  POP3Transport_ParseResponse (TYPE_1__*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugstr_an (char*,int) ; 

__attribute__((used)) static void POP3Transport_CallbackProcessQUITResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("%s\n", debugstr_an(pBuffer, cbBuffer));

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
    InternetTransport_DropConnection(&This->InetTransport);
}