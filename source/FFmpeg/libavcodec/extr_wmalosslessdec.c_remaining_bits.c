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
struct TYPE_3__ {int buf_bit_size; } ;
typedef  TYPE_1__ WmallDecodeCtx ;
typedef  int /*<<< orphan*/  GetBitContext ;

/* Variables and functions */
 int get_bits_count (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int remaining_bits(WmallDecodeCtx *s, GetBitContext *gb)
{
    return s->buf_bit_size - get_bits_count(gb);
}