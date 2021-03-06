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
typedef  enum chan_width { ____Placeholder_chan_width } chan_width ;

/* Variables and functions */
#define  CHAN_WIDTH_160 133 
#define  CHAN_WIDTH_20 132 
#define  CHAN_WIDTH_20_NOHT 131 
#define  CHAN_WIDTH_40 130 
#define  CHAN_WIDTH_80 129 
#define  CHAN_WIDTH_80P80 128 

int channel_width_to_int(enum chan_width width)
{
	switch (width) {
	case CHAN_WIDTH_20_NOHT:
	case CHAN_WIDTH_20:
		return 20;
	case CHAN_WIDTH_40:
		return 40;
	case CHAN_WIDTH_80:
		return 80;
	case CHAN_WIDTH_80P80:
	case CHAN_WIDTH_160:
		return 160;
	default:
		return 0;
	}
}