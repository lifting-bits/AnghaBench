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
 int /*<<< orphan*/  assem_debug (char*,int,int,int) ; 
 int genjmp (int) ; 
 scalar_t__ out ; 
 int /*<<< orphan*/  output_w32 (int) ; 

void emit_jmp(int a)
{
  assem_debug("b %x (%x+%x)\n",a,(int)out,a-(int)out-8);
  u32 offset=genjmp(a);
  output_w32(0xea000000|offset);
}