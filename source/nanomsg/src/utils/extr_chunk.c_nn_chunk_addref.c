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
typedef  int /*<<< orphan*/  uint32_t ;
struct nn_chunk {int /*<<< orphan*/  refcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  nn_atomic_inc (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct nn_chunk* nn_chunk_getptr (void*) ; 

void nn_chunk_addref (void *p, uint32_t n)
{
    struct nn_chunk *self;

    self = nn_chunk_getptr (p);

    nn_atomic_inc (&self->refcount, n);
}