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
typedef  int /*<<< orphan*/  va_list ;

/* Variables and functions */
 int vspprintf (char**,size_t,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int _mysqlnd_vsprintf(char ** pbuf, size_t max_len, const char * format, va_list ap)
{
	return vspprintf(pbuf, max_len, format, ap);
}