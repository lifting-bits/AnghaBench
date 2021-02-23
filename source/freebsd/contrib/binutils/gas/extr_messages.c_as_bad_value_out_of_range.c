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
typedef  int /*<<< orphan*/  offsetT ;

/* Variables and functions */
 int /*<<< orphan*/  as_internal_value_out_of_range (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,unsigned int,int) ; 

void
as_bad_value_out_of_range (char *   prefix,
			   offsetT  value,
			   offsetT  min,
			   offsetT  max,
			   char *   file,
			   unsigned line)
{
  as_internal_value_out_of_range (prefix, value, min, max, file, line, 1);
}