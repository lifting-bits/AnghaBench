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
struct archive_entry {int encryption; } ;

/* Variables and functions */
 int AE_ENCRYPTION_DATA ; 

int
archive_entry_is_data_encrypted(struct archive_entry *entry)
{
	return ((entry->encryption & AE_ENCRYPTION_DATA) == AE_ENCRYPTION_DATA);
}