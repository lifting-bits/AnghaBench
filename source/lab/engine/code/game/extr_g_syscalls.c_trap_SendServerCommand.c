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
 int /*<<< orphan*/  G_SEND_SERVER_COMMAND ; 
 int /*<<< orphan*/  syscall (int /*<<< orphan*/ ,int,char const*) ; 

void trap_SendServerCommand( int clientNum, const char *text ) {
	syscall( G_SEND_SERVER_COMMAND, clientNum, text );
}