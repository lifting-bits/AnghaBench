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
 int __HI (double) ; 

int
finite (double x)
{
  int hx;

  hx = __HI (x);
  return (unsigned) ((hx & 0x7fffffff) - 0x7ff00000) >> 31;
}