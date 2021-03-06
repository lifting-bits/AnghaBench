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
typedef  int /*<<< orphan*/  u64 ;
struct nvkm_vmm_page {int dummy; } ;
struct nvkm_vmm_map {int dummy; } ;
struct nvkm_vmm {int dummy; } ;
typedef  int /*<<< orphan*/  nvkm_vmm_pte_func ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_vmm_iter (struct nvkm_vmm*,struct nvkm_vmm_page const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct nvkm_vmm_map*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
nvkm_vmm_ptes_map(struct nvkm_vmm *vmm, const struct nvkm_vmm_page *page,
		  u64 addr, u64 size, struct nvkm_vmm_map *map,
		  nvkm_vmm_pte_func func)
{
	nvkm_vmm_iter(vmm, page, addr, size, "map", false, false,
		      NULL, func, map, NULL);
}