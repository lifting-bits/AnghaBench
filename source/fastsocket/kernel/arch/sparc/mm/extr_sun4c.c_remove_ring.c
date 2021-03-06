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
struct sun4c_mmu_ring {int /*<<< orphan*/  num_entries; } ;
struct sun4c_mmu_entry {TYPE_1__* prev; struct sun4c_mmu_entry* next; } ;
struct TYPE_2__ {struct sun4c_mmu_entry* next; } ;

/* Variables and functions */

__attribute__((used)) static inline void remove_ring(struct sun4c_mmu_ring *ring,
				   struct sun4c_mmu_entry *entry)
{
	struct sun4c_mmu_entry *next = entry->next;

	(next->prev = entry->prev)->next = next;
	ring->num_entries--;
}