#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* priv_p ;
typedef  int /*<<< orphan*/ * hook_p ;
struct TYPE_3__ {int /*<<< orphan*/ * out; int /*<<< orphan*/ * in; } ;

/* Variables and functions */
 int /*<<< orphan*/  NG_HOOK_NODE (int /*<<< orphan*/ *) ; 
 scalar_t__ NG_NODE_IS_VALID (int /*<<< orphan*/ ) ; 
 scalar_t__ NG_NODE_NUMHOOKS (int /*<<< orphan*/ ) ; 
 TYPE_1__* NG_NODE_PRIVATE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ng_rmnode_self (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ng_patch_disconnect(hook_p hook)
{
	priv_p priv;

	priv = NG_NODE_PRIVATE(NG_HOOK_NODE(hook));

	if (hook == priv->in) {
		priv->in = NULL;
	}

	if (hook == priv->out) {
		priv->out = NULL;
	}

	if (NG_NODE_NUMHOOKS(NG_HOOK_NODE(hook)) == 0 &&
	    NG_NODE_IS_VALID(NG_HOOK_NODE(hook))) /* already shutting down? */
		ng_rmnode_self(NG_HOOK_NODE(hook));

	return (0);
}