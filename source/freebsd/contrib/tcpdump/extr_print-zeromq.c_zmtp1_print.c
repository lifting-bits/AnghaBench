#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int ;
typedef  int /*<<< orphan*/  u_char ;
struct TYPE_5__ {int /*<<< orphan*/  ndo_snapend; } ;
typedef  TYPE_1__ netdissect_options ;

/* Variables and functions */
 int /*<<< orphan*/  ND_PRINT (TYPE_1__*) ; 
 int /*<<< orphan*/ * min (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * zmtp1_print_frame (TYPE_1__*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

void
zmtp1_print(netdissect_options *ndo, const u_char *cp, u_int len)
{
	const u_char *ep = min(ndo->ndo_snapend, cp + len);

	ND_PRINT((ndo, ": ZMTP/1.0"));
	while (cp < ep)
		cp = zmtp1_print_frame(ndo, cp, ep);
}