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
 int /*<<< orphan*/  __f ; 
 int /*<<< orphan*/  assert (int) ; 
 int write (int /*<<< orphan*/ ,void const*,int) ; 

void wdata (const void *x, int len) {
  assert (write (__f, x, len) == len);
}