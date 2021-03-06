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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int ETH_GSTRING_LEN ; 
 int TSE_STATS_LEN ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stat_gstrings ; 

__attribute__((used)) static void tse_gstrings(struct net_device *dev, u32 stringset, u8 *buf)
{
	memcpy(buf, stat_gstrings, TSE_STATS_LEN * ETH_GSTRING_LEN);
}