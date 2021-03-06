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
typedef  scalar_t__ u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct nfp_rtsym {scalar_t__ type; scalar_t__ addr; int /*<<< orphan*/  name; } ;
struct nfp_cpp {int dummy; } ;

/* Variables and functions */
 int ENXIO ; 
 scalar_t__ NFP_RTSYM_TYPE_ABS ; 
 int nfp_cpp_readq (struct nfp_cpp*,int /*<<< orphan*/ ,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  nfp_err (struct nfp_cpp*,char*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ nfp_rtsym_size (struct nfp_rtsym const*) ; 
 int nfp_rtsym_to_dest (struct nfp_cpp*,struct nfp_rtsym const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,scalar_t__*) ; 

int __nfp_rtsym_readq(struct nfp_cpp *cpp, const struct nfp_rtsym *sym,
		      u8 action, u8 token, u64 off, u64 *value)
{
	u32 cpp_id;
	u64 addr;
	int err;

	if (off + 8 > nfp_rtsym_size(sym)) {
		nfp_err(cpp, "rtsym '%s': readq out of bounds: off: %lld + 8 > size: %lld\n",
			sym->name, off, nfp_rtsym_size(sym));
		return -ENXIO;
	}

	if (sym->type == NFP_RTSYM_TYPE_ABS) {
		*value = sym->addr;
		return 0;
	}

	err = nfp_rtsym_to_dest(cpp, sym, action, token, off, &cpp_id, &addr);
	if (err)
		return err;

	return nfp_cpp_readq(cpp, cpp_id, addr, value);
}