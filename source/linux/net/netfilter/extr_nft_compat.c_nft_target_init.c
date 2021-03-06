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
typedef  union nft_entry {int dummy; } nft_entry ;
typedef  int /*<<< orphan*/  u16 ;
struct xt_tgchk_param {int dummy; } ;
struct xt_target {int /*<<< orphan*/  target; } ;
struct nlattr {int dummy; } ;
struct nft_expr {TYPE_1__* ops; } ;
struct nft_ctx {scalar_t__* nla; } ;
struct TYPE_2__ {struct xt_target* data; } ;

/* Variables and functions */
 int EINVAL ; 
 size_t NFTA_RULE_COMPAT ; 
 size_t NFTA_TARGET_INFO ; 
 size_t XT_ALIGN (int /*<<< orphan*/ ) ; 
 void* nft_expr_priv (struct nft_expr const*) ; 
 int nft_parse_compat (scalar_t__,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  nft_target_set_tgchk_param (struct xt_tgchk_param*,struct nft_ctx const*,struct xt_target*,void*,union nft_entry*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nla_data (struct nlattr const* const) ; 
 int /*<<< orphan*/  nla_len (struct nlattr const* const) ; 
 int /*<<< orphan*/  target_compat_from_user (struct xt_target*,int /*<<< orphan*/ ,void*) ; 
 int xt_check_target (struct xt_tgchk_param*,size_t,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
nft_target_init(const struct nft_ctx *ctx, const struct nft_expr *expr,
		const struct nlattr * const tb[])
{
	void *info = nft_expr_priv(expr);
	struct xt_target *target = expr->ops->data;
	struct xt_tgchk_param par;
	size_t size = XT_ALIGN(nla_len(tb[NFTA_TARGET_INFO]));
	u16 proto = 0;
	bool inv = false;
	union nft_entry e = {};
	int ret;

	target_compat_from_user(target, nla_data(tb[NFTA_TARGET_INFO]), info);

	if (ctx->nla[NFTA_RULE_COMPAT]) {
		ret = nft_parse_compat(ctx->nla[NFTA_RULE_COMPAT], &proto, &inv);
		if (ret < 0)
			return ret;
	}

	nft_target_set_tgchk_param(&par, ctx, target, info, &e, proto, inv);

	ret = xt_check_target(&par, size, proto, inv);
	if (ret < 0)
		return ret;

	/* The standard target cannot be used */
	if (!target->target)
		return -EINVAL;

	return 0;
}