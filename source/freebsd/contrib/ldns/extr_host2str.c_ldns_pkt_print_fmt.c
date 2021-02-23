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
typedef  int /*<<< orphan*/  ldns_pkt ;
typedef  int /*<<< orphan*/  ldns_output_format ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  LDNS_FREE (char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 char* ldns_pkt2str_fmt (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

void
ldns_pkt_print_fmt(FILE *output, 
		const ldns_output_format *fmt, const ldns_pkt *pkt)
{
	char *str = ldns_pkt2str_fmt(fmt, pkt);
	if (str) {
		fprintf(output, "%s", str);
	} else {
		fprintf(output, ";Unable to convert packet to string\n");
	}
	LDNS_FREE(str);
}