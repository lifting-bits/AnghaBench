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
typedef  int /*<<< orphan*/  SceUID ;

/* Variables and functions */
 int /*<<< orphan*/  sceGxmUnmapVertexUsseMemory (void*) ; 
 int /*<<< orphan*/  sceKernelFreeMemBlock (int /*<<< orphan*/ ) ; 
 scalar_t__ sceKernelGetMemBlockBase (int /*<<< orphan*/ ,void**) ; 

void vertex_usse_free(SceUID uid)
{
	void *mem = NULL;
	if (sceKernelGetMemBlockBase(uid, &mem) < 0)
		return;
	sceGxmUnmapVertexUsseMemory(mem);
	sceKernelFreeMemBlock(uid);
}