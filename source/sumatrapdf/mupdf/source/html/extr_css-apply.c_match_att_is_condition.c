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
typedef  int /*<<< orphan*/  fz_xml ;

/* Variables and functions */
 char* fz_xml_att (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 

__attribute__((used)) static int
match_att_is_condition(fz_xml *node, const char *key, const char *val)
{
	const char *att = fz_xml_att(node, key);
	return att && !strcmp(val, att);
}