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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 scalar_t__ _COMM_PAGE32_BASE_ADDRESS ; 
 scalar_t__ _COMM_PAGE32_START_ADDRESS ; 
 scalar_t__ _COMM_PAGE_ATM_DIAGNOSTIC_CONFIG ; 
 char* commPagePtr32 ; 
 char* commPagePtr64 ; 

void
commpage_update_atm_diagnostic_config(uint32_t diagnostic_config)
{
	volatile uint32_t *saved_data_ptr;
	char *cp;

	cp = commPagePtr32;
	if (cp) {
		cp += (_COMM_PAGE_ATM_DIAGNOSTIC_CONFIG - _COMM_PAGE32_BASE_ADDRESS);
		saved_data_ptr = (volatile uint32_t *)cp;
		*saved_data_ptr = diagnostic_config;
	}

	cp = commPagePtr64;
	if ( cp ) {
		cp += (_COMM_PAGE_ATM_DIAGNOSTIC_CONFIG - _COMM_PAGE32_START_ADDRESS);
		saved_data_ptr = (volatile uint32_t *)cp;
		*saved_data_ptr = diagnostic_config;
	}
}