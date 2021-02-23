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
typedef  int /*<<< orphan*/ * AT91PS_DataFlash ;

/* Variables and functions */
 int AT91F_DataFlashErase (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * AT91F_DataflashSelect (int /*<<< orphan*/ *,unsigned int*) ; 
 int /*<<< orphan*/  DataFlashInst ; 

int erase_dataflash(unsigned long addr_dest)
{
	unsigned int AddrToWrite = addr_dest;
	AT91PS_DataFlash pFlash = &DataFlashInst;

	pFlash = AT91F_DataflashSelect (pFlash, &AddrToWrite);
	if (AddrToWrite == -1)
		return -1;

	return AT91F_DataFlashErase(pFlash);
}