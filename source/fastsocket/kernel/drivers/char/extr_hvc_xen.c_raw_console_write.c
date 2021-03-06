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
 int /*<<< orphan*/  CONSOLEIO_write ; 
 int HYPERVISOR_console_io (int /*<<< orphan*/ ,int,char*) ; 

__attribute__((used)) static void raw_console_write(const char *str, int len)
{
	while(len > 0) {
		int rc = HYPERVISOR_console_io(CONSOLEIO_write, len, (char *)str);
		if (rc <= 0)
			break;

		str += rc;
		len -= rc;
	}
}