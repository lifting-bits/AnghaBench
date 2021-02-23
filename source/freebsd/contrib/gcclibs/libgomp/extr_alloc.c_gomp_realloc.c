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
 int /*<<< orphan*/  gomp_fatal (char*,unsigned long) ; 
 void* realloc (void*,size_t) ; 

void *
gomp_realloc (void *old, size_t size)
{
  void *ret = realloc (old, size);
  if (ret == NULL)
    gomp_fatal ("Out of memory allocating %lu bytes", (unsigned long) size);
  return ret;
}