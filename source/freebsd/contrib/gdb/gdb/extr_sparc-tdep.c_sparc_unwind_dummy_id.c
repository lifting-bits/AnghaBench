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
struct gdbarch {int dummy; } ;
struct frame_info {int dummy; } ;
struct frame_id {int dummy; } ;
typedef  int /*<<< orphan*/  CORE_ADDR ;

/* Variables and functions */
 int /*<<< orphan*/  SPARC_SP_REGNUM ; 
 struct frame_id frame_id_build (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  frame_pc_unwind (struct frame_info*) ; 
 int /*<<< orphan*/  frame_unwind_register_unsigned (struct frame_info*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct frame_id
sparc_unwind_dummy_id (struct gdbarch *gdbarch, struct frame_info *next_frame)
{
  CORE_ADDR sp;

  sp = frame_unwind_register_unsigned (next_frame, SPARC_SP_REGNUM);
  return frame_id_build (sp, frame_pc_unwind (next_frame));
}