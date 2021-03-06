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
typedef  int /*<<< orphan*/  ut8 ;
struct TYPE_3__ {int size; int /*<<< orphan*/  buf; } ;
typedef  TYPE_1__ RAsmOp ;
typedef  int /*<<< orphan*/  RAsm ;

/* Variables and functions */
 scalar_t__ r_strbuf_get (int /*<<< orphan*/ *) ; 
 int z80asm (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static int do_assemble(RAsm *a, RAsmOp *op, const char *buf) {
	return op->size = z80asm ((ut8*)r_strbuf_get (&op->buf), buf);
}