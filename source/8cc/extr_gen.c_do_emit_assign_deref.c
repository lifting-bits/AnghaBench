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
typedef  int /*<<< orphan*/  Type ;

/* Variables and functions */
 int /*<<< orphan*/  SAVE ; 
 int /*<<< orphan*/  emit (char*,...) ; 
 char* get_int_reg (int /*<<< orphan*/ *,char) ; 
 int /*<<< orphan*/  pop (char*) ; 

__attribute__((used)) static void do_emit_assign_deref(Type *ty, int off) {
    SAVE;
    emit("mov (#rsp), #rcx");
    char *reg = get_int_reg(ty, 'c');
    if (off)
        emit("mov #%s, %d(#rax)", reg, off);
    else
        emit("mov #%s, (#rax)", reg);
    pop("rax");
}