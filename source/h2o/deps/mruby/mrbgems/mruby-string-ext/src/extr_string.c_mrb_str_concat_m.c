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
 int /*<<< orphan*/  mrb_ensure_string_type (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_fixnum_chr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ mrb_fixnum_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_get_args (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_str_concat (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static mrb_value
mrb_str_concat_m(mrb_state *mrb, mrb_value self)
{
  mrb_value str;

  mrb_get_args(mrb, "o", &str);
  if (mrb_fixnum_p(str))
    str = mrb_fixnum_chr(mrb, str);
  else
    str = mrb_ensure_string_type(mrb, str);
  mrb_str_concat(mrb, self, str);
  return self;
}