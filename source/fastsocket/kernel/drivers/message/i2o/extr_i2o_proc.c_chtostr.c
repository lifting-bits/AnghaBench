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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 char* strncat (char*,char*,int) ; 

__attribute__((used)) static char *chtostr(u8 * chars, int n)
{
	char tmp[256];
	tmp[0] = 0;
	return strncat(tmp, (char *)chars, n);
}