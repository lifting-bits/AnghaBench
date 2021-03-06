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
struct io_buffer {scalar_t__ len; scalar_t__ start; } ;

/* Variables and functions */

__attribute__((used)) static void
io_buffer_reset(struct io_buffer *io)
{

	io->start = 0;
	io->len = 0;
}