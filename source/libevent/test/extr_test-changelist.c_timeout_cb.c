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
struct event {int dummy; } ;
typedef  int /*<<< orphan*/  evutil_socket_t ;

/* Variables and functions */
 int /*<<< orphan*/  event_del (struct event*) ; 
 int /*<<< orphan*/  printf (char*) ; 

__attribute__((used)) static void
timeout_cb(evutil_socket_t fd, short event, void *arg)
{
	printf("timeout fired, time to end test\n");
	event_del(*(struct event**)arg);
	return;
}