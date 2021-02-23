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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
struct vmci_queue {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int __vmci_memcpy_to_queue (struct vmci_queue*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t,int) ; 

int
vmci_memcpy_to_queue_local(struct vmci_queue *queue, uint64_t queue_offset,
    const void *src, size_t src_offset, size_t size, int buf_type,
    bool can_block)
{

	ASSERT(can_block);

	return (__vmci_memcpy_to_queue(queue, queue_offset,
	    (uint8_t *)src + src_offset, size, false));
}