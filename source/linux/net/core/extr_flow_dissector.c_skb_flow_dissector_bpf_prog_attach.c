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
typedef  union bpf_attr {int dummy; } bpf_attr ;
struct net {int /*<<< orphan*/  flow_dissector_prog; } ;
struct bpf_prog {int dummy; } ;
struct TYPE_4__ {TYPE_1__* nsproxy; } ;
struct TYPE_3__ {struct net* net_ns; } ;

/* Variables and functions */
 int EEXIST ; 
 TYPE_2__* current ; 
 int /*<<< orphan*/  flow_dissector_mutex ; 
 int /*<<< orphan*/  lockdep_is_held (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ ,struct bpf_prog*) ; 
 struct bpf_prog* rcu_dereference_protected (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int skb_flow_dissector_bpf_prog_attach(const union bpf_attr *attr,
				       struct bpf_prog *prog)
{
	struct bpf_prog *attached;
	struct net *net;

	net = current->nsproxy->net_ns;
	mutex_lock(&flow_dissector_mutex);
	attached = rcu_dereference_protected(net->flow_dissector_prog,
					     lockdep_is_held(&flow_dissector_mutex));
	if (attached) {
		/* Only one BPF program can be attached at a time */
		mutex_unlock(&flow_dissector_mutex);
		return -EEXIST;
	}
	rcu_assign_pointer(net->flow_dissector_prog, prog);
	mutex_unlock(&flow_dissector_mutex);
	return 0;
}