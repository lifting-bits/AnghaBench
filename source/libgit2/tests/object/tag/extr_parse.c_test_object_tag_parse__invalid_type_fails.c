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

/* Variables and functions */
 int /*<<< orphan*/  assert_tag_fails (char const*,int /*<<< orphan*/ ) ; 

void test_object_tag_parse__invalid_type_fails(void)
{
	const char *tag =
		"object a8d447f68076d1520f69649bb52629941be7031f\n"
		"type garbage\n"
		"tag tagname\n"
		"tagger Taggy Mr. Taggart <taggy@taggart.com>\n"
		"\n"
		"Message";
	assert_tag_fails(tag, 0);
}