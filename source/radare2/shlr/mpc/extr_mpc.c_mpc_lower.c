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

/* Variables and functions */
 int /*<<< orphan*/ * mpc_expect (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mpc_oneof (char*) ; 

mpc_parser_t *mpc_lower(void) { return mpc_expect(mpc_oneof("abcdefghijklmnopqrstuvwxyz"), "lowercase letter"); }