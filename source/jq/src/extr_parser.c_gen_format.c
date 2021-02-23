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
typedef  int /*<<< orphan*/  jv ;
typedef  int /*<<< orphan*/  block ;

/* Variables and functions */
 int /*<<< orphan*/  BLOCK (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_call (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_const (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_lambda (int /*<<< orphan*/ ) ; 

__attribute__((used)) static block gen_format(block a, jv fmt) {
  return BLOCK(a, gen_call("format", gen_lambda(gen_const(fmt))));
}