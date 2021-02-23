#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct parse {int nargs; TYPE_1__* argval; } ;
struct TYPE_2__ {int ival; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int AF_INET ; 
 int AF_INET6 ; 
 scalar_t__ REFID_HASH ; 
 int /*<<< orphan*/  apeers (struct parse*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dopeers (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 scalar_t__ drefid ; 

__attribute__((used)) static void
peers(
	struct parse *pcmd,
	FILE *fp
	)
{
	if (drefid == REFID_HASH) {
		apeers(pcmd, fp);
	} else {
		int af = 0;

		if (pcmd->nargs == 1) {
			if (pcmd->argval->ival == 6)
				af = AF_INET6;
			else
				af = AF_INET;
		}
		dopeers(0, fp, af);
	}
}