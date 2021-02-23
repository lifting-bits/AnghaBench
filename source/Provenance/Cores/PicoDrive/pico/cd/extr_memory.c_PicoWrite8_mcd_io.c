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
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  EL_CDREGS ; 
 int /*<<< orphan*/  PicoWrite8_io (int,int) ; 
 int /*<<< orphan*/  SekPc ; 
 int /*<<< orphan*/  elprintf (int /*<<< orphan*/ ,char*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m68k_reg_write8 (int,int) ; 

void PicoWrite8_mcd_io(u32 a, u32 d)
{
  if ((a & 0xff00) == 0x2000) { // a12000 - a120ff
    elprintf(EL_CDREGS, "m68k_regs w8:  [%02x]   %02x @%06x",
      a & 0x3f, d, SekPc);
    m68k_reg_write8(a, d);
    return;
  }

  PicoWrite8_io(a, d);
}