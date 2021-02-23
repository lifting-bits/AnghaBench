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
struct vector_str {size_t size; } ;
struct cpp_demangle_data {scalar_t__ push_head; struct vector_str output; struct vector_str output_tmp; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpp_demangle_read_type (struct cpp_demangle_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  vector_str_pop (struct vector_str*) ; 
 char* vector_str_substr (struct vector_str*,size_t,int,size_t*) ; 

__attribute__((used)) static int
cpp_demangle_read_type_flat(struct cpp_demangle_data *ddata, char **str)
{
	struct vector_str *output;
	size_t i, p_idx, idx, type_len;
	char *type;

	output = ddata->push_head > 0 ? &ddata->output_tmp :
	    &ddata->output;

	p_idx = output->size;

	if (!cpp_demangle_read_type(ddata, 0))
		return (0);

	if ((type = vector_str_substr(output, p_idx, output->size - 1,
	    &type_len)) == NULL)
		return (0);

	idx = output->size;
	for (i = p_idx; i < idx; ++i) {
		if (!vector_str_pop(output)) {
			free(type);
			return (0);
		}
	}

	*str = type;

	return (1);
}