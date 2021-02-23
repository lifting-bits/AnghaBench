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
typedef  int /*<<< orphan*/  u_long ;
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int /*<<< orphan*/  INSIST (int) ; 
 int /*<<< orphan*/  ctl_putunqstr (char const*,char*,int) ; 
 int snprintf (char*,int,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
ctl_putuint(
	const char *tag,
	u_long uval
	)
{
	char buffer[24]; /* needs to fit for 64 bits! */
	int  rc;

	rc = snprintf(buffer, sizeof(buffer), "%lu", uval);
	INSIST(rc >= 0 && (size_t)rc < sizeof(buffer));
	ctl_putunqstr(tag, buffer, rc);
}