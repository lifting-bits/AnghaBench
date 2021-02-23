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
 int /*<<< orphan*/  assem_debug (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  output_w32 (int) ; 
 int rd_rn_rm (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * regname ; 

void emit_rrxs(int rs, int rt)
{
  assem_debug("rrxs %s,%s\n",regname[rt],regname[rs]);
  output_w32(0xe1b00060|rd_rn_rm(rt,0,rs));
}