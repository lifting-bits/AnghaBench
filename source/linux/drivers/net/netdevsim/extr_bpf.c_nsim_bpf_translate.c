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
struct nsim_bpf_bound_prog {char* state; } ;
struct bpf_prog {TYPE_2__* aux; } ;
struct TYPE_4__ {TYPE_1__* offload; } ;
struct TYPE_3__ {struct nsim_bpf_bound_prog* dev_priv; } ;

/* Variables and functions */

__attribute__((used)) static int nsim_bpf_translate(struct bpf_prog *prog)
{
	struct nsim_bpf_bound_prog *state = prog->aux->offload->dev_priv;

	state->state = "xlated";
	return 0;
}