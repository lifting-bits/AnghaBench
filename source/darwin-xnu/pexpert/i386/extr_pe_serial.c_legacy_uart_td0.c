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
 int /*<<< orphan*/  IO_WRITE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  THR ; 

__attribute__((used)) static void
legacy_uart_td0( int c )
{
    IO_WRITE( THR, c );
}