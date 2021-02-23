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
 int /*<<< orphan*/  MANGLE_TRACE_TREE (char*,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  add_substitution (int /*<<< orphan*/  const) ; 
 scalar_t__ find_substitution (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  write_unscoped_name (int /*<<< orphan*/  const) ; 

__attribute__((used)) static void
write_unscoped_template_name (const tree decl)
{
  MANGLE_TRACE_TREE ("unscoped-template-name", decl);

  if (find_substitution (decl))
    return;
  write_unscoped_name (decl);
  add_substitution (decl);
}