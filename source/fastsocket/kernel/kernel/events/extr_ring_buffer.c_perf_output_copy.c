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
struct perf_output_handle {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __output_copy (struct perf_output_handle*,void const*,unsigned int) ; 

void perf_output_copy(struct perf_output_handle *handle,
		      const void *buf, unsigned int len)
{
	__output_copy(handle, buf, len);
}