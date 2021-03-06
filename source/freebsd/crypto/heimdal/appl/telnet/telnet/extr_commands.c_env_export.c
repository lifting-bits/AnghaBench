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
struct env_lst {int export; } ;

/* Variables and functions */
 struct env_lst* env_find (unsigned char*) ; 

void
env_export(unsigned char *var)
{
	struct env_lst *ep;

	if ((ep = env_find(var)))
		ep->export = 1;
}