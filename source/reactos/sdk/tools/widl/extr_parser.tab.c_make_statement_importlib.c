#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char const* str; } ;
struct TYPE_6__ {TYPE_1__ u; } ;
typedef  TYPE_2__ statement_t ;

/* Variables and functions */
 int /*<<< orphan*/  STMT_IMPORTLIB ; 
 TYPE_2__* make_statement (int /*<<< orphan*/ ) ; 

__attribute__((used)) static statement_t *make_statement_importlib(const char *str)
{
    statement_t *stmt = make_statement(STMT_IMPORTLIB);
    stmt->u.str = str;
    return stmt;
}