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
typedef  int u32 ;
struct ce_desc_64 {int dummy; } ;
struct ce_desc {int dummy; } ;
struct ce_attr {int /*<<< orphan*/  src_sz_max; int /*<<< orphan*/  src_nentries; } ;
struct ath10k_ce_ring {int /*<<< orphan*/  base_addr_owner_space; int /*<<< orphan*/  base_addr_ce_space; int /*<<< orphan*/  nentries_mask; int /*<<< orphan*/  write_index; int /*<<< orphan*/  sw_index; int /*<<< orphan*/  hw_index; } ;
struct ath10k_ce_pipe {struct ath10k_ce_ring* src_ring; } ;
struct ath10k_ce {struct ath10k_ce_pipe* ce_states; } ;
struct TYPE_2__ {scalar_t__ target_64bit; } ;
struct ath10k {TYPE_1__ hw_params; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH10K_DBG_BOOT ; 
 int ath10k_ce_base_address (struct ath10k*,unsigned int) ; 
 struct ath10k_ce* ath10k_ce_priv (struct ath10k*) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_base_addr_set (struct ath10k*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_byte_swap_set (struct ath10k*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_dmax_set (struct ath10k*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_highmark_set (struct ath10k*,int,int) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_lowmark_set (struct ath10k*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_read_index_get (struct ath10k*,int) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_size_set (struct ath10k*,int,int) ; 
 int /*<<< orphan*/  ath10k_ce_src_ring_write_index_get (struct ath10k*,int) ; 
 int /*<<< orphan*/  ath10k_dbg (struct ath10k*,int /*<<< orphan*/ ,char*,unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int roundup_pow_of_two (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ath10k_ce_init_src_ring(struct ath10k *ar,
				   unsigned int ce_id,
				   const struct ce_attr *attr)
{
	struct ath10k_ce *ce = ath10k_ce_priv(ar);
	struct ath10k_ce_pipe *ce_state = &ce->ce_states[ce_id];
	struct ath10k_ce_ring *src_ring = ce_state->src_ring;
	u32 nentries, ctrl_addr = ath10k_ce_base_address(ar, ce_id);

	nentries = roundup_pow_of_two(attr->src_nentries);

	if (ar->hw_params.target_64bit)
		memset(src_ring->base_addr_owner_space, 0,
		       nentries * sizeof(struct ce_desc_64));
	else
		memset(src_ring->base_addr_owner_space, 0,
		       nentries * sizeof(struct ce_desc));

	src_ring->sw_index = ath10k_ce_src_ring_read_index_get(ar, ctrl_addr);
	src_ring->sw_index &= src_ring->nentries_mask;
	src_ring->hw_index = src_ring->sw_index;

	src_ring->write_index =
		ath10k_ce_src_ring_write_index_get(ar, ctrl_addr);
	src_ring->write_index &= src_ring->nentries_mask;

	ath10k_ce_src_ring_base_addr_set(ar, ce_id,
					 src_ring->base_addr_ce_space);
	ath10k_ce_src_ring_size_set(ar, ctrl_addr, nentries);
	ath10k_ce_src_ring_dmax_set(ar, ctrl_addr, attr->src_sz_max);
	ath10k_ce_src_ring_byte_swap_set(ar, ctrl_addr, 0);
	ath10k_ce_src_ring_lowmark_set(ar, ctrl_addr, 0);
	ath10k_ce_src_ring_highmark_set(ar, ctrl_addr, nentries);

	ath10k_dbg(ar, ATH10K_DBG_BOOT,
		   "boot init ce src ring id %d entries %d base_addr %pK\n",
		   ce_id, nentries, src_ring->base_addr_owner_space);

	return 0;
}