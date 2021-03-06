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
struct mem_ref_group {struct mem_ref_group* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  prune_group_by_reuse (struct mem_ref_group*) ; 

__attribute__((used)) static void
prune_by_reuse (struct mem_ref_group *groups)
{
  for (; groups; groups = groups->next)
    prune_group_by_reuse (groups);
}