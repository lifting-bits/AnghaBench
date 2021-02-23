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
typedef  int /*<<< orphan*/  mpc_input_t ;

/* Variables and functions */
 int mpc_input_failure (int /*<<< orphan*/ *,char) ; 
 char mpc_input_getc (int /*<<< orphan*/ *) ; 
 int mpc_input_success (int /*<<< orphan*/ *,char,char**) ; 
 scalar_t__ mpc_input_terminated (int /*<<< orphan*/ *) ; 
 scalar_t__ strchr (char const*,char) ; 

__attribute__((used)) static int mpc_input_oneof(mpc_input_t *i, const char *c, char **o) {
  char x = mpc_input_getc(i);
  if (mpc_input_terminated(i)) { return 0; }
  return strchr(c, x) != 0 ? mpc_input_success(i, x, o) : mpc_input_failure(i, x);  
}