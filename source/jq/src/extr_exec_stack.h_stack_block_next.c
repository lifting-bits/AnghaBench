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
struct stack {int dummy; } ;
typedef  int /*<<< orphan*/  stack_ptr ;

/* Variables and functions */
 scalar_t__ stack_block (struct stack*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static stack_ptr* stack_block_next(struct stack* s, stack_ptr p) {
  return &((stack_ptr*)stack_block(s, p))[-1];
}