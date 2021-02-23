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
typedef  int /*<<< orphan*/  lzma_ret ;
typedef  int /*<<< orphan*/  lzma_next_coder ;
typedef  int /*<<< orphan*/  lzma_filter_info ;
typedef  int /*<<< orphan*/  lzma_allocator ;

/* Variables and functions */
 int /*<<< orphan*/  powerpc_coder_init (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int) ; 

extern lzma_ret
lzma_simple_powerpc_decoder_init(lzma_next_coder *next,
		const lzma_allocator *allocator,
		const lzma_filter_info *filters)
{
	return powerpc_coder_init(next, allocator, filters, false);
}