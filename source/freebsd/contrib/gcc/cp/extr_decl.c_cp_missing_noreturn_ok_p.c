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
typedef  int /*<<< orphan*/  tree ;

/* Variables and functions */
 int DECL_MAIN_P (int /*<<< orphan*/ ) ; 

bool
cp_missing_noreturn_ok_p (tree decl)
{
  /* A missing noreturn is ok for the `main' function.  */
  return DECL_MAIN_P (decl);
}