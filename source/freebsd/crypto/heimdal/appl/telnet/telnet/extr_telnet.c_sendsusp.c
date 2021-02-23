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
 int /*<<< orphan*/  IAC ; 
 int /*<<< orphan*/  NET2ADD (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SUSP ; 
 scalar_t__ autoflush ; 
 scalar_t__ autosynch ; 
 int /*<<< orphan*/  doflush () ; 
 int /*<<< orphan*/  dosynch () ; 
 int flushline ; 
 int /*<<< orphan*/  printoption (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
sendsusp(void)
{
    NET2ADD(IAC, SUSP);
    printoption("SENT", IAC, SUSP);
    flushline = 1;
    if (autoflush) {
	doflush();
    }
    if (autosynch) {
	dosynch();
    }
}