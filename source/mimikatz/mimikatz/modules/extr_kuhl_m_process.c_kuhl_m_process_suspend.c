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
 int /*<<< orphan*/  KUHL_M_PROCESS_GENERICOPERATION_SUSPEND ; 
 int /*<<< orphan*/  kuhl_m_process_genericOperation (int,int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 

NTSTATUS kuhl_m_process_suspend(int argc, wchar_t * argv[])
{
	return kuhl_m_process_genericOperation(argc, argv, KUHL_M_PROCESS_GENERICOPERATION_SUSPEND);
}