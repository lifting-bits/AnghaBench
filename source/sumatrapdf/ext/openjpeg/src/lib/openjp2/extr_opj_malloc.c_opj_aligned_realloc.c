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
 void* opj_aligned_realloc_n (void*,unsigned int,size_t) ; 

void * opj_aligned_realloc(void *ptr, size_t size)
{
    return opj_aligned_realloc_n(ptr, 16U, size);
}