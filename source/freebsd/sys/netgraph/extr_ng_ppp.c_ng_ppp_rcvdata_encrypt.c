#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_2__* priv_p ;
typedef  int /*<<< orphan*/  node_p ;
typedef  int /*<<< orphan*/  item_p ;
typedef  int /*<<< orphan*/  hook_p ;
struct TYPE_4__ {int /*<<< orphan*/  enableEncryption; } ;
struct TYPE_5__ {TYPE_1__ conf; } ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  NG_FREE_ITEM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NG_HOOK_NODE (int /*<<< orphan*/ ) ; 
 TYPE_2__* NG_NODE_PRIVATE (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  PROT_CRYPTD ; 
 int ng_ppp_mp_xmit (int /*<<< orphan*/  const,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ng_ppp_rcvdata_encrypt(hook_p hook, item_p item)
{
	const node_p node = NG_HOOK_NODE(hook);
	const priv_p priv = NG_NODE_PRIVATE(node);

	if (!priv->conf.enableEncryption) {
		NG_FREE_ITEM(item);
		return (ENXIO);
	}
	return (ng_ppp_mp_xmit(node, item, PROT_CRYPTD));
}