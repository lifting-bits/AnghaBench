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
struct TYPE_2__ {int /*<<< orphan*/  context; int /*<<< orphan*/  (* callout ) (int,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int FS_BUFFER_CACHE_GC_CALLOUTS_MAX_SIZE ; 
 int /*<<< orphan*/  buf_gc_callout ; 
 TYPE_1__* fs_callouts ; 
 int /*<<< orphan*/  lck_mtx_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
fs_buffer_cache_gc_dispatch_callouts(int all)
{
	lck_mtx_lock(buf_gc_callout);
	for(int i = 0; i < FS_BUFFER_CACHE_GC_CALLOUTS_MAX_SIZE; i++) {
		if (fs_callouts[i].callout != NULL) {
			fs_callouts[i].callout(all, fs_callouts[i].context);
		}
	}
	lck_mtx_unlock(buf_gc_callout);
}