#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int word ;
struct TYPE_3__ {long* c_ind_mask_table; } ;
typedef  TYPE_1__ PLCI ;

/* Variables and functions */

__attribute__((used)) static void set_c_ind_mask_bit (PLCI   *plci, word b)
{
  plci->c_ind_mask_table[b >> 5] |= (1L << (b & 0x1f));
}