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
typedef  int /*<<< orphan*/  IPV6_ADDR ;
typedef  int /*<<< orphan*/  IP ;

/* Variables and functions */
 int IPToIPv6Addr (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int StrToMask6 (int /*<<< orphan*/ *,char*) ; 

bool StrToMask6Addr(IPV6_ADDR *mask, char *str)
{
	IP ip;

	if (StrToMask6(&ip, str) == false)
	{
		return false;
	}

	if (IPToIPv6Addr(mask, &ip) == false)
	{
		return false;
	}

	return true;
}