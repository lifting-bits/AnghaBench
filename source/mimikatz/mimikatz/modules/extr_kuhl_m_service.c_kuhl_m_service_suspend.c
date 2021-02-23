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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/  SERVICE_CONTROL_PAUSE ; 
 int /*<<< orphan*/  genericFunction (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kull_m_service_suspend ; 

NTSTATUS kuhl_m_service_suspend(int argc, wchar_t * argv[])
{
	return genericFunction(kull_m_service_suspend, L"Suspending", argc, argv, SERVICE_CONTROL_PAUSE);
}