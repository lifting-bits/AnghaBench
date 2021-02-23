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
typedef  int /*<<< orphan*/  REFIID ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/  IClassFactory ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  IClassFactory_QueryInterface (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  POP3TransportCF ; 

HRESULT POP3TransportCF_Create(REFIID riid, LPVOID *ppv)
{
    return IClassFactory_QueryInterface((IClassFactory *)&POP3TransportCF, riid, ppv);
}