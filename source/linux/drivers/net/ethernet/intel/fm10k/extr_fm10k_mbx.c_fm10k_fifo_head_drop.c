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
typedef  scalar_t__ u16 ;
struct fm10k_mbx_fifo {int /*<<< orphan*/  head; } ;

/* Variables and functions */
 scalar_t__ fm10k_fifo_head_len (struct fm10k_mbx_fifo*) ; 

__attribute__((used)) static u16 fm10k_fifo_head_drop(struct fm10k_mbx_fifo *fifo)
{
	u16 len = fm10k_fifo_head_len(fifo);

	/* update head so it is at the start of next frame */
	fifo->head += len;

	return len;
}