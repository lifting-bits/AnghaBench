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
 int /*<<< orphan*/ * mpc_and (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpc_soi () ; 
 int /*<<< orphan*/  mpcf_dtor_null ; 
 int /*<<< orphan*/  mpcf_snd ; 

mpc_parser_t *mpc_startwith(mpc_parser_t *a) { return mpc_and(2, mpcf_snd, mpc_soi(), a, mpcf_dtor_null); }