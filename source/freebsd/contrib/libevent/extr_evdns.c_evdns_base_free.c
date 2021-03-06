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
struct evdns_base {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EVDNS_LOCK (struct evdns_base*) ; 
 int /*<<< orphan*/  evdns_base_free_and_unlock (struct evdns_base*,int) ; 

void
evdns_base_free(struct evdns_base *base, int fail_requests)
{
	EVDNS_LOCK(base);
	evdns_base_free_and_unlock(base, fail_requests);
}