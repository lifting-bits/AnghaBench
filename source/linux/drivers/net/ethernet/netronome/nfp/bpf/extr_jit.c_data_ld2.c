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
struct nfp_prog {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  imm; } ;
struct nfp_insn_meta {TYPE_1__ insn; } ;

/* Variables and functions */
 int construct_data_ld (struct nfp_prog*,struct nfp_insn_meta*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int data_ld2(struct nfp_prog *nfp_prog, struct nfp_insn_meta *meta)
{
	return construct_data_ld(nfp_prog, meta, meta->insn.imm, 2);
}