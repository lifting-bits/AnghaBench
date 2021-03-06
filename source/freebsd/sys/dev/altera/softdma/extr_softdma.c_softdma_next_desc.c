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
typedef  int uint32_t ;
struct softdma_channel {int descs_num; } ;

/* Variables and functions */

__attribute__((used)) static inline uint32_t
softdma_next_desc(struct softdma_channel *chan, uint32_t curidx)
{

	return ((curidx + 1) % chan->descs_num);
}