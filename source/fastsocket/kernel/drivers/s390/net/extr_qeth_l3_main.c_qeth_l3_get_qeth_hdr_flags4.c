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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 int /*<<< orphan*/  QETH_CAST_BROADCAST ; 
 int /*<<< orphan*/  QETH_CAST_MULTICAST ; 
 int /*<<< orphan*/  QETH_CAST_UNICAST ; 
 int RTN_BROADCAST ; 
 int RTN_MULTICAST ; 

__attribute__((used)) static inline u8 qeth_l3_get_qeth_hdr_flags4(int cast_type)
{
	if (cast_type == RTN_MULTICAST)
		return QETH_CAST_MULTICAST;
	if (cast_type == RTN_BROADCAST)
		return QETH_CAST_BROADCAST;
	return QETH_CAST_UNICAST;
}