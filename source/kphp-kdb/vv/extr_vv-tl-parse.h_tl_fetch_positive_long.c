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
 long long tl_fetch_long_range (int,int) ; 

__attribute__((used)) static inline long long tl_fetch_positive_long (void) {
  return tl_fetch_long_range (1, 0x7fffffffffffffffll);
}