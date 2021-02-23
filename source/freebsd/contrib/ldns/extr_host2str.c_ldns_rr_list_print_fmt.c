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
typedef  int /*<<< orphan*/  ldns_rr_list ;
typedef  int /*<<< orphan*/  ldns_output_format ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  ldns_rr_list_rr (int /*<<< orphan*/  const*,size_t) ; 
 size_t ldns_rr_list_rr_count (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ldns_rr_print_fmt (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 

void
ldns_rr_list_print_fmt(FILE *output, 
		const ldns_output_format *fmt, const ldns_rr_list *lst)
{
	size_t i;
	for (i = 0; i < ldns_rr_list_rr_count(lst); i++) {
		ldns_rr_print_fmt(output, fmt, ldns_rr_list_rr(lst, i));
	}
}