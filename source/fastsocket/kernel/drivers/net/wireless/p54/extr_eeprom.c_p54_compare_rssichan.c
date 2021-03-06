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
struct p54_rssi_db_entry {int freq; } ;

/* Variables and functions */

__attribute__((used)) static int p54_compare_rssichan(const void *_a,
				const void *_b)
{
	const struct p54_rssi_db_entry *a = _a;
	const struct p54_rssi_db_entry *b = _b;

	return a->freq - b->freq;
}