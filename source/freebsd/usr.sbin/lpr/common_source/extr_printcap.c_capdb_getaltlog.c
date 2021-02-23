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
 scalar_t__ cgetcap (char*,char const*,char) ; 

__attribute__((used)) static int
capdb_getaltlog(char *bp, const char *shrt, const char *lng)
{
	if (cgetcap(bp, lng, ':'))
		return 1;
	if (cgetcap(bp, shrt, ':'))
		return 1;
	return 0;
}