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
struct evkeyvalq {int dummy; } ;

/* Variables and functions */
 int evhttp_parse_query_impl (char const*,struct evkeyvalq*,int,int /*<<< orphan*/ ) ; 

int
evhttp_parse_query(const char *uri, struct evkeyvalq *headers)
{
	return evhttp_parse_query_impl(uri, headers, 1, 0);
}