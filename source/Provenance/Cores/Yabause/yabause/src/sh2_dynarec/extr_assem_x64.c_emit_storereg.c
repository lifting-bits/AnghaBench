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
 int CCREG ; 
 int /*<<< orphan*/  assem_debug (char*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  master_cc ; 
 scalar_t__ master_reg ; 
 scalar_t__ out ; 
 int /*<<< orphan*/  output_byte (int) ; 
 int /*<<< orphan*/  output_modrm (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  output_w32 (int) ; 
 int /*<<< orphan*/ * regname ; 
 scalar_t__ slave ; 
 int /*<<< orphan*/  slave_cc ; 
 scalar_t__ slave_reg ; 

void emit_storereg(int r, int hr)
{
  int addr=(slave?(int)slave_reg:(int)master_reg)+(r<<2);
  if(r==CCREG) addr=slave?(int)&slave_cc:(int)&master_cc;
  assem_debug("mov %%%s,%x+%d\n",regname[hr],addr,r);
  output_byte(0x89);
  output_modrm(0,5,hr);
  output_w32(addr-(int)out-4); // Note: rip-relative in 64-bit mode
}