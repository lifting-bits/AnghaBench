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
 int MODE_PIN5 ; 
 int MODE_PIN8 ; 

__attribute__((used)) static int ap325rxa_mode_pins(void)
{
	/* MD0=0, MD1=0, MD2=0: Clock Mode 0
	 * MD3=0: 16-bit Area0 Bus Width
	 * MD5=1: Little Endian
	 * TSTMD=1, MD8=1: Test Mode Disabled
	 */
	return MODE_PIN5 | MODE_PIN8;
}