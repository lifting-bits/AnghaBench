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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  SM_FLASH_CMD_READ_STATUS ; 
 int SM_FLASH_STATUS_DONE ; 
 int inb (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
wait_operation_complete_sm(uint8_t *bank)
{
	int i;

	for (i = 1000000; i != 0; i--) {
		outb(bank, SM_FLASH_CMD_READ_STATUS);
		if (inb(bank) & SM_FLASH_STATUS_DONE)
			return (0);
	}
	return (-1);
}