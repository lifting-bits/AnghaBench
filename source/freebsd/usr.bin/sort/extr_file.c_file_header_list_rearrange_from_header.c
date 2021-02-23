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
struct file_header {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  file_header_heap_sink (struct file_header**,int /*<<< orphan*/ ,size_t) ; 

__attribute__((used)) static void
file_header_list_rearrange_from_header(struct file_header **fh, size_t size)
{

	file_header_heap_sink(fh, 0, size);
}