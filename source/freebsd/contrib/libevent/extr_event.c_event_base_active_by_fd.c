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
struct event_base {int dummy; } ;
typedef  int /*<<< orphan*/  evutil_socket_t ;

/* Variables and functions */
 int /*<<< orphan*/  EVBASE_ACQUIRE_LOCK (struct event_base*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EVBASE_RELEASE_LOCK (struct event_base*,int /*<<< orphan*/ ) ; 
 short EV_CLOSED ; 
 short EV_READ ; 
 short EV_WRITE ; 
 int /*<<< orphan*/  evmap_io_active_ (struct event_base*,int /*<<< orphan*/ ,short) ; 
 int /*<<< orphan*/  th_base_lock ; 

void
event_base_active_by_fd(struct event_base *base, evutil_socket_t fd, short events)
{
	EVBASE_ACQUIRE_LOCK(base, th_base_lock);
	evmap_io_active_(base, fd, events & (EV_READ|EV_WRITE|EV_CLOSED));
	EVBASE_RELEASE_LOCK(base, th_base_lock);
}