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

/* Variables and functions */
 int NI_USUAL_RTSI_SELECT (unsigned int) ; 

__attribute__((used)) static inline unsigned NI_AO_SCAN_BEGIN_SRC_RTSI(unsigned rtsi_channel) {
		return NI_USUAL_RTSI_SELECT(rtsi_channel);
	}