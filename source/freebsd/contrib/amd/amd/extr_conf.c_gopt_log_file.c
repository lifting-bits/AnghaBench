#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  logfile; } ;

/* Variables and functions */
 TYPE_1__ gopt ; 
 int /*<<< orphan*/  xstrdup (char const*) ; 

__attribute__((used)) static int
gopt_log_file(const char *val)
{
  gopt.logfile = xstrdup(val);
  return 0;
}