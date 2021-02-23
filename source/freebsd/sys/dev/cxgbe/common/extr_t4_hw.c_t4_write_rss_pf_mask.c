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
typedef  int /*<<< orphan*/  u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  A_TP_RSS_PF_MSK ; 
 int /*<<< orphan*/  t4_tp_pio_write (struct adapter*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int) ; 

void t4_write_rss_pf_mask(struct adapter *adapter, u32 pfmask, bool sleep_ok)
{
	t4_tp_pio_write(adapter, &pfmask, 1, A_TP_RSS_PF_MSK, sleep_ok);
}