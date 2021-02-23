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
struct flex_array_part {int /*<<< orphan*/ * elements; } ;
struct flex_array {unsigned int total_nr_elements; int /*<<< orphan*/  element_size; struct flex_array_part** parts; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOSPC ; 
 int /*<<< orphan*/  FLEX_ARRAY_FREE ; 
 scalar_t__ elements_fit_in_base (struct flex_array*) ; 
 int fa_element_to_part_nr (struct flex_array*,unsigned int) ; 
 size_t index_inside_part (struct flex_array*,unsigned int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int flex_array_clear(struct flex_array *fa, unsigned int element_nr)
{
	int part_nr = fa_element_to_part_nr(fa, element_nr);
	struct flex_array_part *part;
	void *dst;

	if (element_nr >= fa->total_nr_elements)
		return -ENOSPC;
	if (elements_fit_in_base(fa))
		part = (struct flex_array_part *)&fa->parts[0];
	else {
		part = fa->parts[part_nr];
		if (!part)
			return -EINVAL;
	}
	dst = &part->elements[index_inside_part(fa, element_nr)];
	memset(dst, FLEX_ARRAY_FREE, fa->element_size);
	return 0;
}