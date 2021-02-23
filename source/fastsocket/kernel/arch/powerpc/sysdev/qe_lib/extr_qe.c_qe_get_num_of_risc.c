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
typedef  unsigned int u32 ;
struct device_node {int dummy; } ;

/* Variables and functions */
 struct device_node* of_find_compatible_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 struct device_node* of_find_node_by_type (int /*<<< orphan*/ *,char*) ; 
 unsigned int* of_get_property (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 

unsigned int qe_get_num_of_risc(void)
{
	struct device_node *qe;
	int size;
	unsigned int num_of_risc = 0;
	const u32 *prop;

	qe = of_find_compatible_node(NULL, NULL, "fsl,qe");
	if (!qe) {
		/* Older devices trees did not have an "fsl,qe"
		 * compatible property, so we need to look for
		 * the QE node by name.
		 */
		qe = of_find_node_by_type(NULL, "qe");
		if (!qe)
			return num_of_risc;
	}

	prop = of_get_property(qe, "fsl,qe-num-riscs", &size);
	if (prop && size == sizeof(*prop))
		num_of_risc = *prop;

	of_node_put(qe);

	return num_of_risc;
}