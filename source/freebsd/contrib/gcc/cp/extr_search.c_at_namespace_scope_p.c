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
typedef  scalar_t__ tree ;

/* Variables and functions */
 scalar_t__ NAMESPACE_DECL ; 
 scalar_t__ TREE_CODE (scalar_t__) ; 
 scalar_t__ current_scope () ; 

bool
at_namespace_scope_p (void)
{
  tree cs = current_scope ();
  return cs && TREE_CODE (cs) == NAMESPACE_DECL;
}