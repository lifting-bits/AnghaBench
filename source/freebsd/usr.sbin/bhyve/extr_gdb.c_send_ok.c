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
 int /*<<< orphan*/  append_string (char*) ; 
 int /*<<< orphan*/  finish_packet () ; 
 int /*<<< orphan*/  start_packet () ; 

__attribute__((used)) static void
send_ok(void)
{

	start_packet();
	append_string("OK");
	finish_packet();
}