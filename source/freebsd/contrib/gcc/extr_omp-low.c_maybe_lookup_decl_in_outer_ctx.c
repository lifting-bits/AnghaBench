#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/ * tree ;
struct TYPE_4__ {struct TYPE_4__* outer; scalar_t__ is_nested; } ;
typedef  TYPE_1__ omp_context ;

/* Variables and functions */
 int /*<<< orphan*/ * maybe_lookup_decl (int /*<<< orphan*/ *,TYPE_1__*) ; 

__attribute__((used)) static tree
maybe_lookup_decl_in_outer_ctx (tree decl, omp_context *ctx)
{
  tree t = NULL;
  omp_context *up;

  if (ctx->is_nested)
    for (up = ctx->outer, t = NULL; up && t == NULL; up = up->outer)
      t = maybe_lookup_decl (decl, up);

  return t ? t : decl;
}