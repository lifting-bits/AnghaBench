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
struct TYPE_3__ {char const* buf; int len; } ;
typedef  TYPE_1__ CtlMemBufT ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  ctl_putdata_ex (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 int strlen (char const*) ; 

__attribute__((used)) static void
ctl_putunqstr(
	const char *	tag,
	const char *	data,
	size_t		len
	)
{
	CtlMemBufT args[3];

	args[0].buf = tag;
	args[0].len = strlen(tag);
	args[1].buf = "=";
	args[1].len = 1;
	if (data && len) {
		args[2].buf = data;
		args[2].len = len;
		ctl_putdata_ex(args, 3, FALSE);
	} else {
		ctl_putdata_ex(args, 2, FALSE);
	}
}