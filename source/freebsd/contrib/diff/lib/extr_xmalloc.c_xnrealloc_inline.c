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
 void* realloc (void*,size_t) ; 
 int /*<<< orphan*/  xalloc_die () ; 
 scalar_t__ xalloc_oversized (size_t,size_t) ; 

__attribute__((used)) static inline void *
xnrealloc_inline (void *p, size_t n, size_t s)
{
  if (xalloc_oversized (n, s) || ! (p = realloc (p, n * s)))
    xalloc_die ();
  return p;
}