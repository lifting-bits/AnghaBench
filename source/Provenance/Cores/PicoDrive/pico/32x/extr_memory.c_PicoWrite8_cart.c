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
 int /*<<< orphan*/  EL_UIO ; 
 int /*<<< orphan*/  SekPc ; 
 int /*<<< orphan*/  elprintf (int /*<<< orphan*/ ,char*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m68k_write8 (int,int) ; 

__attribute__((used)) static void PicoWrite8_cart(u32 a, u32 d)
{
  elprintf(EL_UIO, "m68k w8  [%06x]   %02x @%06x", a, d & 0xff, SekPc);

  a &= 0xfffff;
  m68k_write8(a, d);
}