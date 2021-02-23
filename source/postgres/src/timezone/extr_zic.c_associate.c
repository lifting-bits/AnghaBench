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
struct zone {int z_nrules; char z_format_specifier; int /*<<< orphan*/  z_isdst; int /*<<< orphan*/  z_rule; int /*<<< orphan*/  z_save; int /*<<< orphan*/  z_linenum; int /*<<< orphan*/  z_filename; struct rule* z_rules; } ;
struct rule {int /*<<< orphan*/  r_name; int /*<<< orphan*/  r_filename; int /*<<< orphan*/  r_linenum; } ;
typedef  int ptrdiff_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  eat (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  error (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ errors ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  getsave (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int nrules ; 
 int nzones ; 
 int /*<<< orphan*/  qsort (struct rule*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcomp ; 
 struct rule* rules ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  warning (int /*<<< orphan*/ ) ; 
 struct zone* zones ; 

__attribute__((used)) static void
associate(void)
{
	struct zone *zp;
	struct rule *rp;
	ptrdiff_t	i,
				j,
				base,
				out;

	if (nrules != 0)
	{
		qsort(rules, nrules, sizeof *rules, rcomp);
		for (i = 0; i < nrules - 1; ++i)
		{
			if (strcmp(rules[i].r_name,
					   rules[i + 1].r_name) != 0)
				continue;
			if (strcmp(rules[i].r_filename,
					   rules[i + 1].r_filename) == 0)
				continue;
			eat(rules[i].r_filename, rules[i].r_linenum);
			warning(_("same rule name in multiple files"));
			eat(rules[i + 1].r_filename, rules[i + 1].r_linenum);
			warning(_("same rule name in multiple files"));
			for (j = i + 2; j < nrules; ++j)
			{
				if (strcmp(rules[i].r_name,
						   rules[j].r_name) != 0)
					break;
				if (strcmp(rules[i].r_filename,
						   rules[j].r_filename) == 0)
					continue;
				if (strcmp(rules[i + 1].r_filename,
						   rules[j].r_filename) == 0)
					continue;
				break;
			}
			i = j - 1;
		}
	}
	for (i = 0; i < nzones; ++i)
	{
		zp = &zones[i];
		zp->z_rules = NULL;
		zp->z_nrules = 0;
	}
	for (base = 0; base < nrules; base = out)
	{
		rp = &rules[base];
		for (out = base + 1; out < nrules; ++out)
			if (strcmp(rp->r_name, rules[out].r_name) != 0)
				break;
		for (i = 0; i < nzones; ++i)
		{
			zp = &zones[i];
			if (strcmp(zp->z_rule, rp->r_name) != 0)
				continue;
			zp->z_rules = rp;
			zp->z_nrules = out - base;
		}
	}
	for (i = 0; i < nzones; ++i)
	{
		zp = &zones[i];
		if (zp->z_nrules == 0)
		{
			/*
			 * Maybe we have a local standard time offset.
			 */
			eat(zp->z_filename, zp->z_linenum);
			zp->z_save = getsave(zp->z_rule, &zp->z_isdst);

			/*
			 * Note, though, that if there's no rule, a '%s' in the format is
			 * a bad thing.
			 */
			if (zp->z_format_specifier == 's')
				error("%s", _("%s in ruleless zone"));
		}
	}
	if (errors)
		exit(EXIT_FAILURE);
}