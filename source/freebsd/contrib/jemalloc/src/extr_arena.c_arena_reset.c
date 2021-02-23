#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tsd_t ;
typedef  int /*<<< orphan*/  rtree_ctx_t ;
typedef  int /*<<< orphan*/  extent_t ;
struct TYPE_10__ {scalar_t__ curslabs; scalar_t__ curregs; } ;
struct TYPE_11__ {int /*<<< orphan*/  lock; TYPE_1__ stats; int /*<<< orphan*/  slabs_full; int /*<<< orphan*/  slabs_nonfull; int /*<<< orphan*/ * slabcur; } ;
typedef  TYPE_2__ bin_t ;
struct TYPE_12__ {int /*<<< orphan*/  nactive; TYPE_2__* bins; int /*<<< orphan*/  large_mtx; int /*<<< orphan*/  large; } ;
typedef  TYPE_3__ arena_t ;
struct TYPE_13__ {scalar_t__ szind; int /*<<< orphan*/  slab; } ;
typedef  TYPE_4__ alloc_ctx_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATOMIC_RELAXED ; 
 unsigned int NBINS ; 
 scalar_t__ NSIZES ; 
 int /*<<< orphan*/  arena_bin_slabs_full_remove (TYPE_3__*,TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  arena_slab_dalloc (int /*<<< orphan*/ ,TYPE_3__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  atomic_store_zu (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ config_prof ; 
 scalar_t__ config_stats ; 
 void* extent_base_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * extent_heap_remove_first (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * extent_list_first (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  extents_rtree ; 
 size_t isalloc (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  large_dalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc_mutex_lock (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc_mutex_unlock (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ opt_prof ; 
 int /*<<< orphan*/  prof_free (int /*<<< orphan*/ *,void*,size_t,TYPE_4__*) ; 
 int /*<<< orphan*/  rtree_szind_slab_read (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,uintptr_t,int,scalar_t__*,int /*<<< orphan*/ *) ; 
 size_t sz_index2size (scalar_t__) ; 
 int /*<<< orphan*/ * tsd_rtree_ctx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tsd_tsdn (int /*<<< orphan*/ *) ; 

void
arena_reset(tsd_t *tsd, arena_t *arena) {
	/*
	 * Locking in this function is unintuitive.  The caller guarantees that
	 * no concurrent operations are happening in this arena, but there are
	 * still reasons that some locking is necessary:
	 *
	 * - Some of the functions in the transitive closure of calls assume
	 *   appropriate locks are held, and in some cases these locks are
	 *   temporarily dropped to avoid lock order reversal or deadlock due to
	 *   reentry.
	 * - mallctl("epoch", ...) may concurrently refresh stats.  While
	 *   strictly speaking this is a "concurrent operation", disallowing
	 *   stats refreshes would impose an inconvenient burden.
	 */

	/* Large allocations. */
	malloc_mutex_lock(tsd_tsdn(tsd), &arena->large_mtx);

	for (extent_t *extent = extent_list_first(&arena->large); extent !=
	    NULL; extent = extent_list_first(&arena->large)) {
		void *ptr = extent_base_get(extent);
		size_t usize;

		malloc_mutex_unlock(tsd_tsdn(tsd), &arena->large_mtx);
		alloc_ctx_t alloc_ctx;
		rtree_ctx_t *rtree_ctx = tsd_rtree_ctx(tsd);
		rtree_szind_slab_read(tsd_tsdn(tsd), &extents_rtree, rtree_ctx,
		    (uintptr_t)ptr, true, &alloc_ctx.szind, &alloc_ctx.slab);
		assert(alloc_ctx.szind != NSIZES);

		if (config_stats || (config_prof && opt_prof)) {
			usize = sz_index2size(alloc_ctx.szind);
			assert(usize == isalloc(tsd_tsdn(tsd), ptr));
		}
		/* Remove large allocation from prof sample set. */
		if (config_prof && opt_prof) {
			prof_free(tsd, ptr, usize, &alloc_ctx);
		}
		large_dalloc(tsd_tsdn(tsd), extent);
		malloc_mutex_lock(tsd_tsdn(tsd), &arena->large_mtx);
	}
	malloc_mutex_unlock(tsd_tsdn(tsd), &arena->large_mtx);

	/* Bins. */
	for (unsigned i = 0; i < NBINS; i++) {
		extent_t *slab;
		bin_t *bin = &arena->bins[i];
		malloc_mutex_lock(tsd_tsdn(tsd), &bin->lock);
		if (bin->slabcur != NULL) {
			slab = bin->slabcur;
			bin->slabcur = NULL;
			malloc_mutex_unlock(tsd_tsdn(tsd), &bin->lock);
			arena_slab_dalloc(tsd_tsdn(tsd), arena, slab);
			malloc_mutex_lock(tsd_tsdn(tsd), &bin->lock);
		}
		while ((slab = extent_heap_remove_first(&bin->slabs_nonfull)) !=
		    NULL) {
			malloc_mutex_unlock(tsd_tsdn(tsd), &bin->lock);
			arena_slab_dalloc(tsd_tsdn(tsd), arena, slab);
			malloc_mutex_lock(tsd_tsdn(tsd), &bin->lock);
		}
		for (slab = extent_list_first(&bin->slabs_full); slab != NULL;
		    slab = extent_list_first(&bin->slabs_full)) {
			arena_bin_slabs_full_remove(arena, bin, slab);
			malloc_mutex_unlock(tsd_tsdn(tsd), &bin->lock);
			arena_slab_dalloc(tsd_tsdn(tsd), arena, slab);
			malloc_mutex_lock(tsd_tsdn(tsd), &bin->lock);
		}
		if (config_stats) {
			bin->stats.curregs = 0;
			bin->stats.curslabs = 0;
		}
		malloc_mutex_unlock(tsd_tsdn(tsd), &bin->lock);
	}

	atomic_store_zu(&arena->nactive, 0, ATOMIC_RELAXED);
}