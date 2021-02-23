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
typedef  int matrix_row_t ;

/* Variables and functions */
 int /*<<< orphan*/  GPIOB ; 
 int /*<<< orphan*/  I2C_ADDR_READ ; 
 int /*<<< orphan*/  I2C_ADDR_WRITE ; 
 scalar_t__ I2C_STATUS_SUCCESS ; 
 int /*<<< orphan*/  I2C_TIMEOUT ; 
 int PINF ; 
 int ROW1 ; 
 int ROW2 ; 
 int ROW3 ; 
 int ROW4 ; 
 scalar_t__ i2c_read_nack (int /*<<< orphan*/ ) ; 
 scalar_t__ i2c_start (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_stop () ; 
 scalar_t__ i2c_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ mcp23018_status ; 
 int /*<<< orphan*/  xprintf (char*,int) ; 

__attribute__((used)) static matrix_row_t read_cols(uint8_t row) {
    if (row < 7) {
        if (mcp23018_status) { // if there was an error
            return 0;
        } else {
            uint8_t data = 0;
            mcp23018_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);    if (mcp23018_status) goto out;
            mcp23018_status = i2c_write(GPIOB, I2C_TIMEOUT);             if (mcp23018_status) goto out;
            mcp23018_status = i2c_start(I2C_ADDR_READ, I2C_TIMEOUT);     if (mcp23018_status) goto out;
            mcp23018_status = i2c_read_nack(I2C_TIMEOUT);                if (mcp23018_status < 0) goto out;
            data = ~((uint8_t)mcp23018_status);
            mcp23018_status = I2C_STATUS_SUCCESS;
        out:
            i2c_stop();

#ifdef DEBUG_MATRIX
            if (data != 0x00) xprintf("I2C: %d\n", data);
#endif
            return data;
        }
    } else {
         /* read from teensy
	        * bitmask is 0b0111001, but we want the lower four
	        * we'll return 1s for the top two, but that's harmless.
	        */
        // So I need to confuckulate all this
        //return ~(((PIND & DMASK) >> 1  | ((PINC & CMASK) >> 6) | (PIN)));
        //return ~((PINF & 0x03) | ((PINF & 0xF0) >> 2));
        return ~(
           (((PINF & ROW4) >> 1)
          | ((PINF & (ROW1 | ROW2 | ROW3)) >> 3))
        & 0xF);
    }
}