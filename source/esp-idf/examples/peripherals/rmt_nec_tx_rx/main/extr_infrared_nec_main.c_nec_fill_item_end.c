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
typedef  int /*<<< orphan*/  rmt_item32_t ;

/* Variables and functions */
 int /*<<< orphan*/  NEC_BIT_END ; 
 int /*<<< orphan*/  nec_fill_item_level (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void nec_fill_item_end(rmt_item32_t* item)
{
    nec_fill_item_level(item, NEC_BIT_END, 0x7fff);
}