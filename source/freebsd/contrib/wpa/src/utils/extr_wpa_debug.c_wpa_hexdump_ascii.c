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
 int /*<<< orphan*/  _wpa_hexdump_ascii (int,char const*,void const*,size_t,int) ; 

void wpa_hexdump_ascii(int level, const char *title, const void *buf,
		       size_t len)
{
	_wpa_hexdump_ascii(level, title, buf, len, 1);
}