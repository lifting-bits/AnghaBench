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
struct ck_malloc {int /*<<< orphan*/  (* free ) (struct ck_hs_map*,int /*<<< orphan*/ ,int) ;} ;
struct ck_hs_map {int /*<<< orphan*/  size; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct ck_hs_map*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
ck_hs_map_destroy(struct ck_malloc *m, struct ck_hs_map *map, bool defer)
{

	m->free(map, map->size, defer);
	return;
}