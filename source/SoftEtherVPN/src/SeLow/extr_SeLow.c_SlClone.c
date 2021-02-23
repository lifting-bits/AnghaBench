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
typedef  int /*<<< orphan*/  UINT ;

/* Variables and functions */
 int /*<<< orphan*/  SlCopy (void*,void*,int /*<<< orphan*/ ) ; 
 void* SlMalloc (int /*<<< orphan*/ ) ; 

void *SlClone(void *p, UINT size)
{
	void *ret;
	// Validate arguments
	if (p == NULL)
	{
		return NULL;
	}

	ret = SlMalloc(size);
	SlCopy(ret, p, size);

	return ret;
}