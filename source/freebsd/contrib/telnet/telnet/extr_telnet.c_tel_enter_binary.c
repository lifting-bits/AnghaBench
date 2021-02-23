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
 int /*<<< orphan*/  TELOPT_BINARY ; 
 int /*<<< orphan*/  send_do (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  send_will (int /*<<< orphan*/ ,int) ; 

void
tel_enter_binary(int rw)
{
    if (rw&1)
	send_do(TELOPT_BINARY, 1);
    if (rw&2)
	send_will(TELOPT_BINARY, 1);
}