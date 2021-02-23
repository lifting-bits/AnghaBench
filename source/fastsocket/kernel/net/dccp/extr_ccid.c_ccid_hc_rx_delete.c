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
struct sock {int dummy; } ;
struct ccid {TYPE_1__* ccid_ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  ccid_hc_rx_slab; int /*<<< orphan*/  (* ccid_hc_rx_exit ) (struct sock*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  kmem_cache_free (int /*<<< orphan*/ ,struct ccid*) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 

void ccid_hc_rx_delete(struct ccid *ccid, struct sock *sk)
{
	if (ccid != NULL) {
		if (ccid->ccid_ops->ccid_hc_rx_exit != NULL)
			ccid->ccid_ops->ccid_hc_rx_exit(sk);
		kmem_cache_free(ccid->ccid_ops->ccid_hc_rx_slab, ccid);
	}
}