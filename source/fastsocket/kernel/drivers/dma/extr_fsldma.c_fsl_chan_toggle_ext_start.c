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
struct fsl_dma_chan {int /*<<< orphan*/  feature; } ;

/* Variables and functions */
 int /*<<< orphan*/  FSL_DMA_CHAN_START_EXT ; 

__attribute__((used)) static void fsl_chan_toggle_ext_start(struct fsl_dma_chan *fsl_chan, int enable)
{
	if (enable)
		fsl_chan->feature |= FSL_DMA_CHAN_START_EXT;
	else
		fsl_chan->feature &= ~FSL_DMA_CHAN_START_EXT;
}