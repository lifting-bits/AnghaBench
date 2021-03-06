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

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,void const*,size_t) ; 

__attribute__((used)) static inline void cd_copy_data(uint8_t **pos, const void *in, size_t size)
{
	memcpy(*pos, &size, sizeof(size_t));
	*pos += sizeof(size_t);

	if (size) {
		memcpy(*pos, in, size);
		*pos += size;
	}
}