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
 int /*<<< orphan*/  assem_debug (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  output_w32 (int) ; 
 int rd_rn_rm (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * regname ; 

void emit_shrimm(int rs,unsigned int imm,int rt)
{
  assert(imm>0);
  assert(imm<32);
  assem_debug("lsr %s,%s,#%d\n",regname[rt],regname[rs],imm);
  output_w32(0xe1a00000|rd_rn_rm(rt,0,rs)|0x20|(imm<<7));
}