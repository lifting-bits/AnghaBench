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
struct sockaddr_in6 {int /*<<< orphan*/  sin6_addr; } ;
struct in6_addr {int /*<<< orphan*/  sin6_addr; } ;
struct addrinfo {scalar_t__ ai_family; int /*<<< orphan*/ * ai_addr; int /*<<< orphan*/  ai_protocol; int /*<<< orphan*/  ai_socktype; } ;
typedef  int /*<<< orphan*/  hint ;
typedef  int /*<<< orphan*/  addr ;
typedef  int /*<<< orphan*/  IP ;

/* Variables and functions */
 scalar_t__ AF_INET6 ; 
 int /*<<< orphan*/  Copy (struct sockaddr_in6*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  GetLocalHostIP6 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  InAddrToIP6 (int /*<<< orphan*/ *,struct sockaddr_in6*) ; 
 scalar_t__ IsEmptyStr (char*) ; 
 int /*<<< orphan*/  NewDnsCache (char*,int /*<<< orphan*/ *) ; 
 int QueryDnsCacheEx (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 scalar_t__ StrCmpi (char*,char*) ; 
 int StrToIP (int /*<<< orphan*/ *,char*) ; 
 int StrToIP6 (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  Zero (struct addrinfo*,int) ; 
 int /*<<< orphan*/  freeaddrinfo (struct addrinfo*) ; 
 scalar_t__ getaddrinfo (char*,int /*<<< orphan*/ *,struct addrinfo*,struct addrinfo**) ; 

bool GetIP6Inner(IP *ip, char *hostname)
{
	struct sockaddr_in6 in;
	struct in6_addr addr;
	struct addrinfo hint;
	struct addrinfo *info;
	// Validate arguments
	if (ip == NULL || hostname == NULL)
	{
		return false;
	}

	if (IsEmptyStr(hostname))
	{
		return false;
	}

	if (StrCmpi(hostname, "localhost") == 0)
	{
		GetLocalHostIP6(ip);
		return true;
	}

	if (StrToIP6(ip, hostname) == false && StrToIP(ip, hostname) == false)
	{
		// Forward resolution
		Zero(&hint, sizeof(hint));
		hint.ai_family = AF_INET6;
		hint.ai_socktype = SOCK_STREAM;
		hint.ai_protocol = IPPROTO_TCP;
		info = NULL;

		if (getaddrinfo(hostname, NULL, &hint, &info) != 0 ||
			info->ai_family != AF_INET6)
		{
			if (info)
			{
				freeaddrinfo(info);
			}
			return QueryDnsCacheEx(ip, hostname, true);
		}
		// Forward resolution success
		Copy(&in, info->ai_addr, sizeof(struct sockaddr_in6));
		freeaddrinfo(info);

		Copy(&addr, &in.sin6_addr, sizeof(addr));
		InAddrToIP6(ip, &addr);
	}

	// Save Cache
	NewDnsCache(hostname, ip);

	return true;
}