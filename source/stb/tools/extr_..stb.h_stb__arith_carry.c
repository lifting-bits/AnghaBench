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
struct TYPE_3__ {int pending_ffs; int /*<<< orphan*/  output; int /*<<< orphan*/  buffered_u8; } ;
typedef  TYPE_1__ stb_arith ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  stb_putc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void stb__arith_carry(stb_arith *a)
{
   int i;
   assert(a->pending_ffs != -1); // can't carry with no data
   stb_putc(a->output, a->buffered_u8);
   for (i=0; i < a->pending_ffs; ++i)
      stb_putc(a->output, 0);
}