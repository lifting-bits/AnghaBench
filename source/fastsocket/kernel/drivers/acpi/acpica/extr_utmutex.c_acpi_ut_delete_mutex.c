#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  acpi_status ;
typedef  size_t acpi_mutex_handle ;
struct TYPE_2__ {int /*<<< orphan*/  thread_id; int /*<<< orphan*/ * mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_U32 (int /*<<< orphan*/ ,size_t) ; 
 size_t ACPI_MAX_MUTEX ; 
 int /*<<< orphan*/  ACPI_MUTEX_NOT_ACQUIRED ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_OK ; 
 TYPE_1__* acpi_gbl_mutex_info ; 
 int /*<<< orphan*/  acpi_os_delete_mutex (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ut_delete_mutex ; 

__attribute__((used)) static acpi_status acpi_ut_delete_mutex(acpi_mutex_handle mutex_id)
{

	ACPI_FUNCTION_TRACE_U32(ut_delete_mutex, mutex_id);

	if (mutex_id > ACPI_MAX_MUTEX) {
		return_ACPI_STATUS(AE_BAD_PARAMETER);
	}

	acpi_os_delete_mutex(acpi_gbl_mutex_info[mutex_id].mutex);

	acpi_gbl_mutex_info[mutex_id].mutex = NULL;
	acpi_gbl_mutex_info[mutex_id].thread_id = ACPI_MUTEX_NOT_ACQUIRED;

	return_ACPI_STATUS(AE_OK);
}