#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ tp_col; } ;
struct TYPE_6__ {scalar_t__ tp_col; } ;
struct TYPE_8__ {int /*<<< orphan*/  t_stateflags; TYPE_2__ t_cursor; TYPE_1__ t_winsize; } ;
typedef  TYPE_3__ teken_t ;

/* Variables and functions */
 int /*<<< orphan*/  TS_WRAPPED ; 
 int /*<<< orphan*/  teken_funcs_cursor (TYPE_3__*) ; 

__attribute__((used)) static void
teken_subr_cursor_forward(teken_t *t, unsigned int ncols)
{

	if (t->t_cursor.tp_col + ncols >= t->t_winsize.tp_col)
		t->t_cursor.tp_col = t->t_winsize.tp_col - 1;
	else
		t->t_cursor.tp_col += ncols;
	t->t_stateflags &= ~TS_WRAPPED;
	teken_funcs_cursor(t);
}