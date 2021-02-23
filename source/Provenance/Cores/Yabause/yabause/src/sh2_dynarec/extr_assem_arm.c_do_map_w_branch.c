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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 scalar_t__ can_direct_write (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_jne (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_testimm (int,int) ; 
 scalar_t__ out ; 

int do_map_w_branch(int map, int c, u32 addr, int *jaddr)
{
  if(!c||can_direct_write(addr)) {
    emit_testimm(map,0x40000000);
    *jaddr=(int)out;
    emit_jne(0);
  }
}