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
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 char* iMajorError ; 
 char* iMinorError ; 
 scalar_t__ major_freebsd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  makedev_freebsd (unsigned long,unsigned long) ; 
 scalar_t__ minor_freebsd (int /*<<< orphan*/ ) ; 
 char* tooManyFields ; 

__attribute__((used)) static dev_t
pack_freebsd(int n, unsigned long numbers[], const char **error)
{
	dev_t dev = 0;

	if (n == 2) {
		dev = makedev_freebsd(numbers[0], numbers[1]);
		if ((unsigned long)major_freebsd(dev) != numbers[0])
			*error = iMajorError;
		if ((unsigned long)minor_freebsd(dev) != numbers[1])
			*error = iMinorError;
	} else
		*error = tooManyFields;
	return (dev);
}