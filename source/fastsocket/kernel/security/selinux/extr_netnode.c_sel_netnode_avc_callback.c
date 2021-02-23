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
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 scalar_t__ AVC_CALLBACK_RESET ; 
 int /*<<< orphan*/  sel_netnode_flush () ; 
 int /*<<< orphan*/  synchronize_net () ; 

__attribute__((used)) static int sel_netnode_avc_callback(u32 event, u32 ssid, u32 tsid,
				    u16 class, u32 perms, u32 *retained)
{
	if (event == AVC_CALLBACK_RESET) {
		sel_netnode_flush();
		synchronize_net();
	}
	return 0;
}