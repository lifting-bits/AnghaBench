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
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;

/* Variables and functions */
 int /*<<< orphan*/ ** environ ; 
 int /*<<< orphan*/  mrb_fixnum_value (int) ; 

__attribute__((used)) static mrb_value
mrb_env_size(mrb_state *mrb, mrb_value self)
{
  int i;

  for (i = 0; environ[i] != NULL; i++)
    ;

  return mrb_fixnum_value(i);
}