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
struct hostent_data {int dummy; } ;

/* Variables and functions */
 struct hostent_data* __hostent_data_init () ; 
 int /*<<< orphan*/  _endhostdnsent () ; 
 int /*<<< orphan*/  _endhosthtent (struct hostent_data*) ; 

void
endhostent(void)
{
	struct hostent_data *hed;

	if ((hed = __hostent_data_init()) == NULL)
		return;
	_endhosthtent(hed);
	_endhostdnsent();
}