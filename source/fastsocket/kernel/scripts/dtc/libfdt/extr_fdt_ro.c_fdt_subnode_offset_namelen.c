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
 int /*<<< orphan*/  FDT_CHECK_HEADER (void const*) ; 
 int FDT_ERR_NOTFOUND ; 
 scalar_t__ _fdt_nodename_eq (void const*,int,char const*,int) ; 
 int fdt_next_node (void const*,int,int*) ; 

int fdt_subnode_offset_namelen(const void *fdt, int offset,
			       const char *name, int namelen)
{
	int depth;

	FDT_CHECK_HEADER(fdt);

	for (depth = 0, offset = fdt_next_node(fdt, offset, &depth);
	     (offset >= 0) && (depth > 0);
	     offset = fdt_next_node(fdt, offset, &depth)) {
		if (depth < 0)
			return -FDT_ERR_NOTFOUND;
		else if ((depth == 1)
			 && _fdt_nodename_eq(fdt, offset, name, namelen))
			return offset;
	}

	if (offset < 0)
		return offset; /* error */
	else
		return -FDT_ERR_NOTFOUND;
}