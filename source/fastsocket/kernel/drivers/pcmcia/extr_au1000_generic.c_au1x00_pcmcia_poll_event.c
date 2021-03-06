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
struct au1000_pcmcia_socket {int /*<<< orphan*/  poll_timer; } ;

/* Variables and functions */
 scalar_t__ AU1000_PCMCIA_POLL_PERIOD ; 
 int /*<<< orphan*/  au1x00_check_status (struct au1000_pcmcia_socket*) ; 
 int /*<<< orphan*/  debug (char*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static void au1x00_pcmcia_poll_event(unsigned long dummy)
{
	struct au1000_pcmcia_socket *skt = (struct au1000_pcmcia_socket *)dummy;
	debug("polling for events\n");

	mod_timer(&skt->poll_timer, jiffies + AU1000_PCMCIA_POLL_PERIOD);

	au1x00_check_status(skt);
}