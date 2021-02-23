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

/* Variables and functions */
#define  SIGINT 129 
#define  SIGTERM 128 
 int /*<<< orphan*/  dns_shutdown () ; 
 int /*<<< orphan*/  fatalx (char*) ; 

void
dns_sig_handler(int sig, short event, void *p)
{
	switch (sig) {
	case SIGINT:
	case SIGTERM:
		dns_shutdown();
		break;
	default:
		fatalx("unexpected signal");
	}
}