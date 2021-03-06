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
typedef  scalar_t__ ll ;

/* Variables and functions */

int cmp_ll (const void *_x, const void *_y) {
  ll x = *(ll *)_x, y = *(ll *)_y;
  if (x < y) {
    return -1;
  } else if (y < x) {
    return 1;                     	
  }
  return 0;
}