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
struct cf_parser {int dummy; } ;

/* Variables and functions */
 int PARSE_EOF ; 
 int cf_get_name (struct cf_parser*,char**,char const*,char const*) ; 
 int /*<<< orphan*/  cf_next_valid_token (struct cf_parser*) ; 

__attribute__((used)) static inline int cf_next_name(struct cf_parser *p, char **dst,
			       const char *name, const char *goto_token)
{
	if (!cf_next_valid_token(p))
		return PARSE_EOF;

	return cf_get_name(p, dst, name, goto_token);
}