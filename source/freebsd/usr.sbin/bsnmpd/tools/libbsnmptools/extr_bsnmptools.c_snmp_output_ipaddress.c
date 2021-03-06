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
typedef  int uint8_t ;
struct snmp_toolinfo {int dummy; } ;
struct TYPE_2__ {char* str; } ;

/* Variables and functions */
 scalar_t__ GET_OUTPUT (struct snmp_toolinfo*) ; 
 scalar_t__ OUTPUT_VERBOSE ; 
 size_t SNMP_SYNTAX_IPADDRESS ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  stdout ; 
 TYPE_1__* syntax_strings ; 

__attribute__((used)) static void
snmp_output_ipaddress(struct snmp_toolinfo *snmptoolctx, uint8_t *ip)
{
	if (GET_OUTPUT(snmptoolctx) == OUTPUT_VERBOSE)
		fprintf(stdout, "%s : ",
		    syntax_strings[SNMP_SYNTAX_IPADDRESS].str);

	fprintf(stdout, "%u.%u.%u.%u", ip[0], ip[1], ip[2], ip[3]);
}