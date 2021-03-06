#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct dma_channel {unsigned int chan; } ;
struct TYPE_4__ {TYPE_1__* channel; } ;
struct TYPE_3__ {scalar_t__ xfer_enable; scalar_t__ chan_enable; } ;

/* Variables and functions */
 TYPE_2__* g2_dma ; 

__attribute__((used)) static int g2_disable_dma(struct dma_channel *chan)
{
	unsigned int chan_nr = chan->chan;

	g2_dma->channel[chan_nr].chan_enable = 0;
	g2_dma->channel[chan_nr].xfer_enable = 0;

	return 0;
}