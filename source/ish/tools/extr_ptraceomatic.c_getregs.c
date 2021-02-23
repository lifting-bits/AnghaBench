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
struct user_regs_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PTRACE_GETREGS ; 
 int /*<<< orphan*/  ptrace (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,struct user_regs_struct*) ; 
 int /*<<< orphan*/  trycall (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static inline void getregs(int pid, struct user_regs_struct *regs) {
    trycall(ptrace(PTRACE_GETREGS, pid, NULL, regs), "ptrace getregs");
}