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
 int /*<<< orphan*/  assemble_external (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  block_move_fn ; 
 int /*<<< orphan*/  init_block_move_fn (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  make_decl_rtl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static tree
emit_block_move_libcall_fn (int for_call)
{
  static bool emitted_extern;

  if (!block_move_fn)
    init_block_move_fn (NULL);

  if (for_call && !emitted_extern)
    {
      emitted_extern = true;
      make_decl_rtl (block_move_fn);
      assemble_external (block_move_fn);
    }

  return block_move_fn;
}