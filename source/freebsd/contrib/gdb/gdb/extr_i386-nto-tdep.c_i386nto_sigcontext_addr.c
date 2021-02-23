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
struct frame_info {int dummy; } ;
typedef  scalar_t__ CORE_ADDR ;

/* Variables and functions */
 scalar_t__ I386_NTO_SIGCONTEXT_OFFSET ; 
 int /*<<< orphan*/  SP_REGNUM ; 
 scalar_t__ extract_unsigned_integer (char*,int) ; 
 int /*<<< orphan*/  frame_unwind_register (struct frame_info*,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static CORE_ADDR
i386nto_sigcontext_addr (struct frame_info *next_frame)
{
  char buf[4];
  CORE_ADDR sp;

  frame_unwind_register (next_frame, SP_REGNUM, buf);
  sp = extract_unsigned_integer (buf, 4);

  return sp + I386_NTO_SIGCONTEXT_OFFSET;
}