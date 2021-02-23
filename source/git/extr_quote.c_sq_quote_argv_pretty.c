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
struct strbuf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sq_append_quote_argv_pretty (struct strbuf*,char const**) ; 
 int /*<<< orphan*/  strbuf_addch (struct strbuf*,char) ; 

void sq_quote_argv_pretty(struct strbuf *dst, const char **argv)
{
	if (argv[0])
		strbuf_addch(dst, ' ');
	sq_append_quote_argv_pretty(dst, argv);
}