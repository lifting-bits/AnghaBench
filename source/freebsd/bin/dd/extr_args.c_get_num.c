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
typedef  int uintmax_t ;

/* Variables and functions */
 int /*<<< orphan*/  ERANGE ; 
 int /*<<< orphan*/  err (int,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  errx (int,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  oper ; 
 int postfix_to_mult (char) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 
 int strtoumax (char const*,char**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uintmax_t
get_num(const char *val)
{
	uintmax_t num, mult, prevnum;
	char *expr;

	errno = 0;
	num = strtoumax(val, &expr, 0);
	if (expr == val)			/* No valid digits. */
		errx(1, "%s: invalid numeric value", oper);
	if (errno != 0)
		err(1, "%s", oper);

	mult = postfix_to_mult(*expr);

	if (mult != 0) {
		prevnum = num;
		num *= mult;
		/* Check for overflow. */
		if (num / mult != prevnum)
			goto erange;
		expr++;
	}

	switch (*expr) {
		case '\0':
			break;
		case '*':			/* Backward compatible. */
		case 'X':
		case 'x':
			mult = get_num(expr + 1);
			prevnum = num;
			num *= mult;
			if (num / mult == prevnum)
				break;
erange:
			errx(1, "%s: %s", oper, strerror(ERANGE));
		default:
			errx(1, "%s: illegal numeric value", oper);
	}
	return (num);
}