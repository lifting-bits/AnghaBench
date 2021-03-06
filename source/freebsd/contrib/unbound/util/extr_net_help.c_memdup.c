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
 void* malloc (size_t) ; 
 int /*<<< orphan*/  memcpy (void*,void*,size_t) ; 

void* 
memdup(void* data, size_t len)
{
	void* d;
	if(!data) return NULL;
	if(len == 0) return NULL;
	d = malloc(len);
	if(!d) return NULL;
	memcpy(d, data, len);
	return d;
}