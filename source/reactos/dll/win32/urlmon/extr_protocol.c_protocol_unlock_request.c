#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ lock; } ;
typedef  TYPE_1__ Protocol ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  InternetUnlockRequestFile (scalar_t__) ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  WARN (char*,int /*<<< orphan*/ ) ; 

HRESULT protocol_unlock_request(Protocol *protocol)
{
    if(!protocol->lock)
        return S_OK;

    if(!InternetUnlockRequestFile(protocol->lock))
        WARN("InternetUnlockRequest failed: %d\n", GetLastError());
    protocol->lock = 0;

    return S_OK;
}