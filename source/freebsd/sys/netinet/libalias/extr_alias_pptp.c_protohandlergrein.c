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
struct libalias {int packetAliasMode; } ;
struct ip {int dummy; } ;
struct alias_data {int dummy; } ;

/* Variables and functions */
 scalar_t__ AliasHandlePptpGreIn (struct libalias*,struct ip*) ; 
 int PKT_ALIAS_PROXY_ONLY ; 

__attribute__((used)) static int
protohandlergrein(struct libalias *la, struct ip *pip, struct alias_data *ah)
{

	if (la->packetAliasMode & PKT_ALIAS_PROXY_ONLY ||
	    AliasHandlePptpGreIn(la, pip) == 0)
		return (0);
	return (-1);
}