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
 void* MEMCPY_EARLY_FUNC (void*,void const*,size_t) ; 

void *
memcpy_early(void *to, const void *from, size_t len)
{

	return (MEMCPY_EARLY_FUNC(to, from, len));
}