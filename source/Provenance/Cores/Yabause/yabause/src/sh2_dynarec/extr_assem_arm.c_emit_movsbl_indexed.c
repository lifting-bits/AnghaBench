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
 int /*<<< orphan*/  assem_debug (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  output_w32 (int) ; 
 int rd_rn_rm (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * regname ; 

void emit_movsbl_indexed(int offset, int rs, int rt)
{
  assert(offset>-256&&offset<256);
  assem_debug("ldrsb %s,%s+%d\n",regname[rt],regname[rs],offset);
  if(offset>=0) {
    output_w32(0xe1d000d0|rd_rn_rm(rt,rs,0)|((offset<<4)&0xf00)|(offset&0xf));
  }else{
    output_w32(0xe15000d0|rd_rn_rm(rt,rs,0)|(((-offset)<<4)&0xf00)|((-offset)&0xf));
  }
}