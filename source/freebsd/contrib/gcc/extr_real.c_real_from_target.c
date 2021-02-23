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
struct real_format {int /*<<< orphan*/  (* decode ) (struct real_format const*,int /*<<< orphan*/ *,long const*) ;} ;
typedef  enum machine_mode { ____Placeholder_machine_mode } machine_mode ;
typedef  int /*<<< orphan*/  REAL_VALUE_TYPE ;

/* Variables and functions */
 struct real_format* REAL_MODE_FORMAT (int) ; 
 int /*<<< orphan*/  gcc_assert (struct real_format const*) ; 
 int /*<<< orphan*/  stub1 (struct real_format const*,int /*<<< orphan*/ *,long const*) ; 

void
real_from_target (REAL_VALUE_TYPE *r, const long *buf, enum machine_mode mode)
{
  const struct real_format *fmt;

  fmt = REAL_MODE_FORMAT (mode);
  gcc_assert (fmt);

  (*fmt->decode) (fmt, r, buf);
}