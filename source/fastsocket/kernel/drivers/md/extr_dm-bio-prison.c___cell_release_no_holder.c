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
struct dm_bio_prison_cell {int /*<<< orphan*/  bios; int /*<<< orphan*/  list; } ;
struct bio_list {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bio_list_merge (struct bio_list*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hlist_del (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void __cell_release_no_holder(struct dm_bio_prison_cell *cell,
				     struct bio_list *inmates)
{
	hlist_del(&cell->list);
	bio_list_merge(inmates, &cell->bios);
}