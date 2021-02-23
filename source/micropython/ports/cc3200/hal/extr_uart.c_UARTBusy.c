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
typedef  int tBoolean ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int HWREG (scalar_t__) ; 
 int /*<<< orphan*/  UARTBaseValid (unsigned long) ; 
 int UART_FR_BUSY ; 
 scalar_t__ UART_O_FR ; 

tBoolean
UARTBusy(unsigned long ulBase)
{
    //
    // Check the argument.
    //
    ASSERT(UARTBaseValid(ulBase));

    //
    // Determine if the UART is busy.
    //
    return((HWREG(ulBase + UART_O_FR) & UART_FR_BUSY) ? true : false);
}