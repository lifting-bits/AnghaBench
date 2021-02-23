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

/* Variables and functions */
 int /*<<< orphan*/  kmem_cache_destroy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kstat_delete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * zil_ksp ; 
 int /*<<< orphan*/  zil_lwb_cache ; 
 int /*<<< orphan*/  zil_zcw_cache ; 

void
zil_fini(void)
{
	kmem_cache_destroy(zil_zcw_cache);
	kmem_cache_destroy(zil_lwb_cache);

	if (zil_ksp != NULL) {
		kstat_delete(zil_ksp);
		zil_ksp = NULL;
	}
}