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
struct mmc_card {int dummy; } ;
struct mmc_blk_data {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int mmc_blk_add_debugfs(struct mmc_card *card, struct mmc_blk_data *md)
{
	return 0;
}