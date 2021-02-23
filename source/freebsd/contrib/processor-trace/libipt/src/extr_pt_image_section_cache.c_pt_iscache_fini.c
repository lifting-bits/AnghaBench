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
struct pt_image_section_cache {int /*<<< orphan*/  lock; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pt_iscache_clear (struct pt_image_section_cache*) ; 

void pt_iscache_fini(struct pt_image_section_cache *iscache)
{
	if (!iscache)
		return;

	(void) pt_iscache_clear(iscache);
	free(iscache->name);

#if defined(FEATURE_THREADS)

	mtx_destroy(&iscache->lock);

#endif /* defined(FEATURE_THREADS) */
}