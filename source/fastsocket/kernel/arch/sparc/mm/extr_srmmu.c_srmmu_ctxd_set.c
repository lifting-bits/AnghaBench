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
typedef  int /*<<< orphan*/  pte_t ;
typedef  int /*<<< orphan*/  pgd_t ;
typedef  int /*<<< orphan*/  ctxd_t ;

/* Variables and functions */
 int SRMMU_ET_PTD ; 
 int __nocache_pa (unsigned long) ; 
 int /*<<< orphan*/  srmmu_set_pte (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline void srmmu_ctxd_set(ctxd_t *ctxp, pgd_t *pgdp)
{ srmmu_set_pte((pte_t *)ctxp, (SRMMU_ET_PTD | (__nocache_pa((unsigned long) pgdp) >> 4))); }