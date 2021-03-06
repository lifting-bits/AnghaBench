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

/* Variables and functions */
 int MMIO_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MMIO_WRITE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SCR ; 

__attribute__((used)) static int
mmio_uart_present( void )
{
    MMIO_WRITE( SCR, 0x5a );
    if (MMIO_READ(SCR) != 0x5a) return 0;
    MMIO_WRITE( SCR, 0xa5 );
    if (MMIO_READ(SCR) != 0xa5) return 0;
    return 1;
}