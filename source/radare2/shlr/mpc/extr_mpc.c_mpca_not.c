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
typedef  int /*<<< orphan*/  mpc_parser_t ;
typedef  int /*<<< orphan*/  mpc_dtor_t ;

/* Variables and functions */
 scalar_t__ mpc_ast_delete ; 
 int /*<<< orphan*/ * mpc_not (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

mpc_parser_t *mpca_not(mpc_parser_t *a) { return mpc_not(a, (mpc_dtor_t)mpc_ast_delete); }