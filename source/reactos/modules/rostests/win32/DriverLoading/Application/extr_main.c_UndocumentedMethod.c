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
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 char* DRIVER_NAME ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  NtStartDriver (char*) ; 
 int /*<<< orphan*/  NtStopDriver (char*) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  UnregisterDriver (char*) ; 
 int /*<<< orphan*/  wprintf (char*,...) ; 

__attribute__((used)) static BOOL
UndocumentedMethod(LPCWSTR lpDriverPath)
{
    wprintf(L"\nStarting %s.sys via native API\n", DRIVER_NAME);

    if (!NtStartDriver(DRIVER_NAME))
    {
        wprintf(L"[%lu] Failed to start %s\n", GetLastError(), DRIVER_NAME);
        UnregisterDriver(DRIVER_NAME);
        return FALSE;
    }

    wprintf(L"\tStarted\n");

    wprintf(L"Stopping %s.sys  via native API\n", DRIVER_NAME);

    if (!NtStopDriver(DRIVER_NAME))
    {
        wprintf(L"[%lu] Failed to stop %s\n", GetLastError(), DRIVER_NAME);
        UnregisterDriver(DRIVER_NAME);
        return FALSE;
    }

    wprintf(L"\tStopped\n");

    return TRUE;
}