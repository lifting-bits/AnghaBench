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
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 

__attribute__((used)) static char *firstchars(char *p, int nch)
{
	static char buf[2][128];
	static int t = 0;
	t = !t;
	memcpy(buf[t], p, nch);
	buf[t][nch] = 0;
	return buf[t];
}