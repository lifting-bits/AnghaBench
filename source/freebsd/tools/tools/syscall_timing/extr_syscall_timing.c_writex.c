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
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  err (int,char*) ; 
 int write (int,char const*,size_t) ; 

__attribute__((used)) static void
writex(int fd, const char *buf, size_t size)
{
	ssize_t ret;

	do {
		ret = write(fd, buf, size);
		if (ret == -1)
			err(1, "write");
		assert((size_t)ret <= size);
		size -= ret;
		buf += ret;
	} while (size > 0);
}