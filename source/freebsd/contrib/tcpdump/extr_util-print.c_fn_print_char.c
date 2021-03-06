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
typedef  int u_char ;
typedef  int /*<<< orphan*/  netdissect_options ;

/* Variables and functions */
 int /*<<< orphan*/  ND_ISASCII (int) ; 
 int /*<<< orphan*/  ND_ISPRINT (int) ; 
 int /*<<< orphan*/  ND_PRINT (int /*<<< orphan*/ *) ; 
 int ND_TOASCII (int) ; 

void
fn_print_char(netdissect_options *ndo, u_char c)
{
	if (!ND_ISASCII(c)) {
		c = ND_TOASCII(c);
		ND_PRINT((ndo, "M-"));
	}
	if (!ND_ISPRINT(c)) {
		c ^= 0x40;	/* DEL to ?, others to alpha */
		ND_PRINT((ndo, "^"));
	}
	ND_PRINT((ndo, "%c", c));
}