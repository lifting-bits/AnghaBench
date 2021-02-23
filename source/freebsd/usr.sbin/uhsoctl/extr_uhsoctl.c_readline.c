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
 int read (int,char*,int) ; 

__attribute__((used)) static int
readline(int fd, char *buf, size_t bufsz)
{
	int n = 0, pos = 0;
	char *p = buf;

	for (;;) {
		n = read(fd, p, 1);
		if (n <= 0)
			break;
		pos++;
		if (pos >= (bufsz - 1))
			break;
		if (*p++ == '\n')
			break;
	}
	*p = '\0';
	return (n <= 0 ? n : pos);
}