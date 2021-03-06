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
typedef  int u8 ;
struct wmi_data_hdr {int info; } ;

/* Variables and functions */
 int WMI_DATA_HDR_UP_MASK ; 
 int WMI_DATA_HDR_UP_SHIFT ; 

__attribute__((used)) static inline void wmi_data_hdr_set_up(struct wmi_data_hdr *dhdr,
				       u8 usr_pri)
{
	dhdr->info &= ~(WMI_DATA_HDR_UP_MASK << WMI_DATA_HDR_UP_SHIFT);
	dhdr->info |= usr_pri << WMI_DATA_HDR_UP_SHIFT;
}