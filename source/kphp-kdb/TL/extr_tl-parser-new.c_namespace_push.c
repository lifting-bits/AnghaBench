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

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int namespace_level ; 
 int /*<<< orphan*/  tl_clear_fields () ; 
 int /*<<< orphan*/  tl_clear_vars () ; 

void namespace_push (void) {
  namespace_level ++;
  assert (namespace_level < 10);
  tl_clear_vars ();
  tl_clear_fields ();
}