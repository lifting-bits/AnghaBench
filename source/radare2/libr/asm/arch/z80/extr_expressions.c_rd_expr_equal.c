#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int line; } ;

/* Variables and functions */
 int addr ; 
 char* delspc (char const*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int,...) ; 
 int rd_expr_unequal (char const**,int*,int,int*,int) ; 
 size_t sp ; 
 TYPE_1__* stack ; 
 int /*<<< orphan*/  stderr ; 
 int verbose ; 

__attribute__((used)) static int
rd_expr_equal (const char **p, int *valid, int level, int *check,
	       int print_errors)
{
  int result;
  if (verbose >= 6)
    fprintf (stderr, "%5d (0x%04x): Starting to read equality epression "
	     "(string=%s).\n", stack[sp].line, addr, *p);
  result = rd_expr_unequal (p, valid, level, check, print_errors);
  *p = delspc (*p);
  if (**p == '=')
    {
      *check = 0;
      ++*p;
      if (**p == '=')
	++ * p;
      return result == rd_expr_equal (p, valid, level, check, print_errors);
    }
  else if (**p == '!' && (*p)[1] == '=')
    {
      *check = 0;
      (*p) += 2;
      return result != rd_expr_equal (p, valid, level, check, print_errors);
    }
  if (verbose >= 7)
    fprintf (stderr, "%5d (0x%04x): rd_equal returned %d (%04x).\n",
	     stack[sp].line, addr, result, result);
  return result;
}