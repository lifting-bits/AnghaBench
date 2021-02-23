#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  aest_dev; int /*<<< orphan*/  aest_devminor; scalar_t__ aest_dev_is_broken_down; } ;
struct archive_entry {TYPE_1__ ae_stat; } ;
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 int /*<<< orphan*/  minor (int /*<<< orphan*/ ) ; 

dev_t
archive_entry_devminor(struct archive_entry *entry)
{
	if (entry->ae_stat.aest_dev_is_broken_down)
		return (entry->ae_stat.aest_devminor);
	else
		return minor(entry->ae_stat.aest_dev);
}