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
struct TYPE_2__ {int /*<<< orphan*/  qe; } ;
struct bfa_meminfo_s {TYPE_1__ kva_info; } ;
struct bfa_mem_kva_s {size_t mem_len; int /*<<< orphan*/  qe; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void bfa_mem_kva_setup(struct bfa_meminfo_s *meminfo,
				     struct bfa_mem_kva_s *kva_ptr,
				     size_t seg_sz)
{
	kva_ptr->mem_len = seg_sz;
	if (seg_sz)
		list_add_tail(&kva_ptr->qe, &meminfo->kva_info.qe);
}