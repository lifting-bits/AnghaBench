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
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  IntEnable (scalar_t__) ; 
 int /*<<< orphan*/  IntRegister (scalar_t__,void (*) ()) ; 
 int _I2CBaseValid (scalar_t__) ; 
 scalar_t__ _I2CIntNumberGet (scalar_t__) ; 

void
I2CIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint32_t ui32Int;

    //
    // Check the arguments.
    //
    ASSERT(_I2CBaseValid(ui32Base));

    //
    // Determine the interrupt number based on the I2C port.
    //
    ui32Int = _I2CIntNumberGet(ui32Base);

    ASSERT(ui32Int != 0);

    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(ui32Int, pfnHandler);

    //
    // Enable the I2C interrupt.
    //
    IntEnable(ui32Int);
}