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
typedef  scalar_t__ du_int ;
typedef  scalar_t__ di_int ;

/* Variables and functions */
 int /*<<< orphan*/  compilerrt_abort () ; 

di_int __addvdi3(di_int a, di_int b) {
  di_int s = (du_int)a + (du_int)b;
  if (b >= 0) {
    if (s < a)
      compilerrt_abort();
  } else {
    if (s >= a)
      compilerrt_abort();
  }
  return s;
}