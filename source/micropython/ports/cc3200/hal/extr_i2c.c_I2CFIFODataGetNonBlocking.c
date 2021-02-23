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
typedef  int uint8_t ;
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int HWREG (int) ; 
 int I2C_FIFOSTATUS_RXFE ; 
 int I2C_O_FIFODATA ; 
 int I2C_O_FIFOSTATUS ; 
 int /*<<< orphan*/  _I2CBaseValid (int) ; 

uint32_t
I2CFIFODataGetNonBlocking(uint32_t ui32Base, uint8_t *pui8Data)
{
    //
    // Check the arguments.
    //
    ASSERT(_I2CBaseValid(ui32Base));

    //
    // If nothing in the FIFO, return zero.
    //
    if(HWREG(ui32Base + I2C_O_FIFOSTATUS) & I2C_FIFOSTATUS_RXFE)
    {
        return(0);
    }
    else
    {
        *pui8Data = HWREG(ui32Base + I2C_O_FIFODATA);
        return(1);
    }
}