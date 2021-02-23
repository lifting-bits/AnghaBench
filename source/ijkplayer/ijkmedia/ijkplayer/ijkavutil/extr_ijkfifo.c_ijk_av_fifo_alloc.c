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
typedef  int /*<<< orphan*/  IjkFifoBuffer ;

/* Variables and functions */
 int /*<<< orphan*/ * fifo_alloc_common (void*,unsigned int) ; 
 void* malloc (unsigned int) ; 

IjkFifoBuffer *ijk_av_fifo_alloc(unsigned int size)
{
    void *buffer = malloc(size);
    return fifo_alloc_common(buffer, size);
}