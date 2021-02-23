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
struct ifaddrs {struct ifaddrs* ifa_next; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct ifaddrs*) ; 

void freeifaddrs(struct ifaddrs *ifa)
{
   struct ifaddrs *l_cur = NULL;

   while(ifa)
   {
      l_cur = ifa;
      ifa = ifa->ifa_next;
      free(l_cur);
   }
}