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
 int /*<<< orphan*/  EVDNS_UNLOCK (struct evdns_base*) ; 
 int /*<<< orphan*/  evdns_requests_pump_waiting_queue (struct evdns_base*) ; 

int
evdns_base_resume(struct evdns_base *base)
{
	EVDNS_LOCK(base);
	evdns_requests_pump_waiting_queue(base);
	EVDNS_UNLOCK(base);

	return 0;
}