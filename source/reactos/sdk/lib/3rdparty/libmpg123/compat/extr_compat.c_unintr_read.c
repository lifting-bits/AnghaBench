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
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 scalar_t__ EINTR ; 
 scalar_t__ errno ; 
 scalar_t__ read (int,char*,size_t) ; 

size_t unintr_read(int fd, void *buffer, size_t bytes)
{
	size_t got = 0;
	while(bytes)
	{
		ssize_t part = read(fd, (char*)buffer+got, bytes);
		if(part < 0 && errno != EINTR)
			break;
		bytes -= part;
		got   += part;
	}
	return got;
}