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
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 int DAIF_IRQF ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  MRS (int,char*) ; 
 int /*<<< orphan*/  TRUE ; 

boolean_t ml_get_interrupts_enabled(void)
{
	uint64_t	value;

	MRS(value, "DAIF");
	if (value & DAIF_IRQF)
		return FALSE;
	return TRUE;
}