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
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 scalar_t__ PXSEG (unsigned long) ; 
 int /*<<< orphan*/  ctrl_outw (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  maybebadio (unsigned long) ; 
 unsigned long port2adr (unsigned long) ; 

void titan_outw(u16 value, unsigned long port)
{
        if (PXSEG(port))
                ctrl_outw(value, port);
        else if (port >= 0x2000)
                ctrl_outw(value, port2adr(port));
        else
                maybebadio(port);
}