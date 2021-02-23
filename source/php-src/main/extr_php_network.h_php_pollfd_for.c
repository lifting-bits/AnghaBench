#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct timeval {int dummy; } ;
typedef  int /*<<< orphan*/  php_socket_t ;
struct TYPE_3__ {int events; int revents; int /*<<< orphan*/  fd; } ;
typedef  TYPE_1__ php_pollfd ;

/* Variables and functions */
 int php_poll2 (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  php_tvtoto (struct timeval*) ; 

__attribute__((used)) static inline int php_pollfd_for(php_socket_t fd, int events, struct timeval *timeouttv)
{
	php_pollfd p;
	int n;

	p.fd = fd;
	p.events = events;
	p.revents = 0;

	n = php_poll2(&p, 1, php_tvtoto(timeouttv));

	if (n > 0) {
		return p.revents;
	}

	return n;
}