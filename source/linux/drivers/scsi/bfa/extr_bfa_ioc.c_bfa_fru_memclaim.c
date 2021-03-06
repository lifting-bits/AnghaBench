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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct bfa_fru_s {int /*<<< orphan*/ * dbuf_kva; int /*<<< orphan*/  dbuf_pa; } ;
typedef  scalar_t__ bfa_boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_DMA_ALIGN_SZ ; 
 int /*<<< orphan*/  BFA_FRU_DMA_BUF_SZ ; 
 scalar_t__ BFA_ROUNDUP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
bfa_fru_memclaim(struct bfa_fru_s *fru, u8 *dm_kva, u64 dm_pa,
	bfa_boolean_t mincfg)
{
	if (mincfg)
		return;

	fru->dbuf_kva = dm_kva;
	fru->dbuf_pa = dm_pa;
	memset(fru->dbuf_kva, 0, BFA_FRU_DMA_BUF_SZ);
	dm_kva += BFA_ROUNDUP(BFA_FRU_DMA_BUF_SZ, BFA_DMA_ALIGN_SZ);
	dm_pa += BFA_ROUNDUP(BFA_FRU_DMA_BUF_SZ, BFA_DMA_ALIGN_SZ);
}