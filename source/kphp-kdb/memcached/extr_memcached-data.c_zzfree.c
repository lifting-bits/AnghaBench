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
 int MAX_ZMALLOC_MEM ; 
 int /*<<< orphan*/  free (void*) ; 
 int malloc_mem ; 
 int /*<<< orphan*/  zfree (void*,int) ; 

void zzfree (void *ptr, int size) {
  if (size < MAX_ZMALLOC_MEM) {
    zfree (ptr, size);
  } else {
    malloc_mem -= size;
    free (ptr);
  }
}