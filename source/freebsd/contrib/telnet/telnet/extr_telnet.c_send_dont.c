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
 int /*<<< orphan*/  DONT ; 
 int /*<<< orphan*/  IAC ; 
 int /*<<< orphan*/  NET2ADD (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NETADD (int) ; 
 scalar_t__* do_dont_resp ; 
 scalar_t__ my_state_is_dont (int) ; 
 scalar_t__ my_want_state_is_dont (int) ; 
 int /*<<< orphan*/  printoption (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  set_my_want_state_dont (int) ; 
 scalar_t__ telnetport ; 

void
send_dont(int c, int init)
{
    if (init) {
	if (((do_dont_resp[c] == 0) && my_state_is_dont(c)) ||
				my_want_state_is_dont(c))
	    return;
	set_my_want_state_dont(c);
	do_dont_resp[c]++;
    }
    if (telnetport < 0)
	return;
    NET2ADD(IAC, DONT);
    NETADD(c);
    printoption("SENT", DONT, c);
}