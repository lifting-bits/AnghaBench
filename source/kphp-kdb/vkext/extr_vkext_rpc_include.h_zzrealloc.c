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
 int /*<<< orphan*/  ADD_REALLOC (long long,long long) ; 
 int /*<<< orphan*/  assert (void*) ; 
 void* realloc (void*,long long) ; 

__attribute__((used)) static inline void *zzrealloc (void *p, long long x, long long y) {
  void *r = realloc (p, y);
  assert (r);
  ADD_REALLOC (x, y);
  return r;
}