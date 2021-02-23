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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int NTB_PEER_PORT_COUNT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 

int
ntb_peer_port_count(device_t ntb)
{
	return (NTB_PEER_PORT_COUNT(device_get_parent(ntb)));
}