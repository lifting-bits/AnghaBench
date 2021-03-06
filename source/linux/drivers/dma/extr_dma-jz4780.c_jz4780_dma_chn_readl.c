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
typedef  int /*<<< orphan*/  uint32_t ;
struct jz4780_dma_dev {scalar_t__ chn_base; } ;

/* Variables and functions */
 scalar_t__ JZ_DMA_REG_CHAN (unsigned int) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 

__attribute__((used)) static inline uint32_t jz4780_dma_chn_readl(struct jz4780_dma_dev *jzdma,
	unsigned int chn, unsigned int reg)
{
	return readl(jzdma->chn_base + reg + JZ_DMA_REG_CHAN(chn));
}