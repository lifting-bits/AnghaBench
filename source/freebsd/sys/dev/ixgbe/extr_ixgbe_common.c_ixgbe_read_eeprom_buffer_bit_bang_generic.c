#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u16 ;
struct TYPE_4__ {int /*<<< orphan*/  (* init_params ) (struct ixgbe_hw*) ;} ;
struct TYPE_3__ {scalar_t__ word_size; TYPE_2__ ops; } ;
struct ixgbe_hw {TYPE_1__ eeprom; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUGFUNC (char*) ; 
 scalar_t__ IXGBE_EEPROM_RD_BUFFER_MAX_COUNT ; 
 scalar_t__ IXGBE_ERR_EEPROM ; 
 scalar_t__ IXGBE_ERR_INVALID_ARGUMENT ; 
 scalar_t__ IXGBE_SUCCESS ; 
 scalar_t__ ixgbe_read_eeprom_buffer_bit_bang (struct ixgbe_hw*,scalar_t__,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  stub1 (struct ixgbe_hw*) ; 

s32 ixgbe_read_eeprom_buffer_bit_bang_generic(struct ixgbe_hw *hw, u16 offset,
					      u16 words, u16 *data)
{
	s32 status = IXGBE_SUCCESS;
	u16 i, count;

	DEBUGFUNC("ixgbe_read_eeprom_buffer_bit_bang_generic");

	hw->eeprom.ops.init_params(hw);

	if (words == 0) {
		status = IXGBE_ERR_INVALID_ARGUMENT;
		goto out;
	}

	if (offset + words > hw->eeprom.word_size) {
		status = IXGBE_ERR_EEPROM;
		goto out;
	}

	/*
	 * We cannot hold synchronization semaphores for too long
	 * to avoid other entity starvation. However it is more efficient
	 * to read in bursts than synchronizing access for each word.
	 */
	for (i = 0; i < words; i += IXGBE_EEPROM_RD_BUFFER_MAX_COUNT) {
		count = (words - i) / IXGBE_EEPROM_RD_BUFFER_MAX_COUNT > 0 ?
			IXGBE_EEPROM_RD_BUFFER_MAX_COUNT : (words - i);

		status = ixgbe_read_eeprom_buffer_bit_bang(hw, offset + i,
							   count, &data[i]);

		if (status != IXGBE_SUCCESS)
			break;
	}

out:
	return status;
}