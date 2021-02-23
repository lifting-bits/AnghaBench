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
struct bpf_insn {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rump_schedule () ; 
 int /*<<< orphan*/  rump_unschedule () ; 
 int rumpns_bpf_validate (struct bpf_insn*,size_t) ; 

__attribute__((used)) static inline bool
prog_validate(struct bpf_insn *insns, size_t insn_count)
{
	bool res;

	rump_schedule();
	res = rumpns_bpf_validate(insns, insn_count);
	rump_unschedule();

	return res;
}