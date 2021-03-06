#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ index; int /*<<< orphan*/  flags; int /*<<< orphan*/  dim; } ;
struct TYPE_3__ {scalar_t__ index; int /*<<< orphan*/  flags; int /*<<< orphan*/  dim; } ;
struct xt_set_info_target_v1 {TYPE_2__ del_set; TYPE_1__ add_set; } ;
struct xt_action_param {struct xt_set_info_target_v1* targinfo; } ;
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADT_OPT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ IPSET_INVALID_ID ; 
 int /*<<< orphan*/  UINT_MAX ; 
 unsigned int XT_CONTINUE ; 
 int /*<<< orphan*/  add_opt ; 
 int /*<<< orphan*/  del_opt ; 
 int /*<<< orphan*/  ip_set_add (scalar_t__,struct sk_buff*,struct xt_action_param const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ip_set_del (scalar_t__,struct sk_buff*,struct xt_action_param const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xt_family (struct xt_action_param const*) ; 

__attribute__((used)) static unsigned int
set_target_v1(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct xt_set_info_target_v1 *info = par->targinfo;

	ADT_OPT(add_opt, xt_family(par), info->add_set.dim,
		info->add_set.flags, 0, UINT_MAX,
		0, 0, 0, 0);
	ADT_OPT(del_opt, xt_family(par), info->del_set.dim,
		info->del_set.flags, 0, UINT_MAX,
		0, 0, 0, 0);

	if (info->add_set.index != IPSET_INVALID_ID)
		ip_set_add(info->add_set.index, skb, par, &add_opt);
	if (info->del_set.index != IPSET_INVALID_ID)
		ip_set_del(info->del_set.index, skb, par, &del_opt);

	return XT_CONTINUE;
}