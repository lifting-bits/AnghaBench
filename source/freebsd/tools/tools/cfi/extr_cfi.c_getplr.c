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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  CFIOCGPLR ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  err (int,char*) ; 
 int getfd (int /*<<< orphan*/ ) ; 
 scalar_t__ ioctl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static uint32_t
getplr(void)
{
	uint32_t plr;
	int fd = getfd(O_RDONLY);
	if (ioctl(fd, CFIOCGPLR, &plr) < 0)
		err(-1, "ioctl(CFIOCGPLR)");
	close(fd);
	return plr;
}