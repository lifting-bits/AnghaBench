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
struct pr_handle {int /*<<< orphan*/  f; } ;
typedef  int /*<<< orphan*/  bfd_boolean ;

/* Variables and functions */
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,double) ; 
 int /*<<< orphan*/  indent (struct pr_handle*) ; 

__attribute__((used)) static bfd_boolean
pr_float_constant (void *p, const char *name, double val)
{
  struct pr_handle *info = (struct pr_handle *) p;

  indent (info);
  fprintf (info->f, "const double %s = %g;\n", name, val);
  return TRUE;
}