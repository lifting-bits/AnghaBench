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
struct TYPE_3__ {int varno; int /*<<< orphan*/  expr; } ;
typedef  TYPE_1__ PLpgSQL_stmt_assign ;

/* Variables and functions */
 int /*<<< orphan*/  dump_expr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dump_ind () ; 
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static void
dump_assign(PLpgSQL_stmt_assign *stmt)
{
	dump_ind();
	printf("ASSIGN var %d := ", stmt->varno);
	dump_expr(stmt->expr);
	printf("\n");
}