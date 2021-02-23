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
struct ck_rhs_map {long (* probe_func ) (struct ck_rhs*,struct ck_rhs_map*,unsigned long*,long*,unsigned long,void const*,void const**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int capacity; scalar_t__ n_entries; scalar_t__ max_entries; int /*<<< orphan*/ * generation; int /*<<< orphan*/  probe_limit; } ;
struct ck_rhs_entry_desc {int in_rh; unsigned long probes; } ;
struct ck_rhs {int /*<<< orphan*/  mode; struct ck_rhs_map* map; } ;

/* Variables and functions */
 void* CK_CC_DECONST_PTR (void const*) ; 
 scalar_t__ CK_CC_UNLIKELY (int) ; 
 unsigned long CK_RHS_G_MASK ; 
 int /*<<< orphan*/  CK_RHS_PROBE_INSERT ; 
 int /*<<< orphan*/  ck_pr_fence_atomic_store () ; 
 int /*<<< orphan*/  ck_pr_inc_uint (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ck_pr_store_ptr (int /*<<< orphan*/ ,void const*) ; 
 int /*<<< orphan*/  ck_rhs_add_wanted (struct ck_rhs*,long,int,unsigned long) ; 
 struct ck_rhs_entry_desc* ck_rhs_desc (struct ck_rhs_map*,long) ; 
 int /*<<< orphan*/  ck_rhs_do_backward_shift_delete (struct ck_rhs*,long) ; 
 int /*<<< orphan*/  ck_rhs_entry_addr (struct ck_rhs_map*,long) ; 
 int ck_rhs_grow (struct ck_rhs*,int) ; 
 int /*<<< orphan*/  ck_rhs_map_bound_set (struct ck_rhs_map*,unsigned long,unsigned long) ; 
 void* ck_rhs_marshal (int /*<<< orphan*/ ,void const*,unsigned long) ; 
 int ck_rhs_put_robin_hood (struct ck_rhs*,long,struct ck_rhs_entry_desc*) ; 
 int /*<<< orphan*/  ck_rhs_set_probes (struct ck_rhs_map*,long,unsigned long) ; 
 long stub1 (struct ck_rhs*,struct ck_rhs_map*,unsigned long*,long*,unsigned long,void const*,void const**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool
ck_rhs_set(struct ck_rhs *hs,
    unsigned long h,
    const void *key,
    void **previous)
{
	long slot, first;
	const void *object;
	const void *insert;
	unsigned long n_probes;
	struct ck_rhs_map *map;

	*previous = NULL;

restart:
	map = hs->map;

	slot = map->probe_func(hs, map, &n_probes, &first, h, key, &object, map->probe_limit, CK_RHS_PROBE_INSERT);
	if (slot == -1 && first == -1) {
		if (ck_rhs_grow(hs, map->capacity << 1) == false)
			return false;

		goto restart;
	}
	ck_rhs_map_bound_set(map, h, n_probes);
	insert = ck_rhs_marshal(hs->mode, key, h);

	if (first != -1) {
		struct ck_rhs_entry_desc *desc = NULL, *desc2;
		if (slot != -1) {
			desc = ck_rhs_desc(map, slot);
			desc->in_rh = true;
		}
		desc2 = ck_rhs_desc(map, first);
		int ret = ck_rhs_put_robin_hood(hs, first, desc2);
		if (slot != -1)
			desc->in_rh = false;

		if (CK_CC_UNLIKELY(ret == 1))
			goto restart;
		if (CK_CC_UNLIKELY(ret == -1))
			return false;
		/* If an earlier bucket was found, then store entry there. */
		ck_pr_store_ptr(ck_rhs_entry_addr(map, first), insert);
		desc2->probes = n_probes;
		/*
		 * If a duplicate key was found, then delete it after
		 * signaling concurrent probes to restart. Optionally,
		 * it is possible to install tombstone after grace
		 * period if we can guarantee earlier position of
		 * duplicate key.
		 */
		ck_rhs_add_wanted(hs, first, -1, h);
		if (object != NULL) {
			ck_pr_inc_uint(&map->generation[h & CK_RHS_G_MASK]);
			ck_pr_fence_atomic_store();
			ck_rhs_do_backward_shift_delete(hs, slot);
		}

	} else {
		/*
		 * If we are storing into same slot, then atomic store is sufficient
		 * for replacement.
		 */
		ck_pr_store_ptr(ck_rhs_entry_addr(map, slot), insert);
		ck_rhs_set_probes(map, slot, n_probes);
		if (object == NULL)
			ck_rhs_add_wanted(hs, slot, -1, h);
	}

	if (object == NULL) {
		map->n_entries++;
		if ((map->n_entries ) > map->max_entries)
			ck_rhs_grow(hs, map->capacity << 1);
	}

	*previous = CK_CC_DECONST_PTR(object);
	return true;
}