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
typedef  int /*<<< orphan*/  JSON_VALUE ;

/* Variables and functions */
 int /*<<< orphan*/ * parse_value (char**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  parson_free (char*) ; 
 char* parson_strdup (char*) ; 
 int /*<<< orphan*/  remove_comments (char*,char*,char*) ; 

JSON_VALUE * JsonParseStringWithComments(char *string) {
	JSON_VALUE *result = NULL;
	char *string_mutable_copy = NULL, *string_mutable_copy_ptr = NULL;
	string_mutable_copy = parson_strdup(string);
	if (string_mutable_copy == NULL) {
		return NULL;
	}
	remove_comments(string_mutable_copy, "/*", "*/");
	remove_comments(string_mutable_copy, "//", "\n");
	string_mutable_copy_ptr = string_mutable_copy;
	result = parse_value((char**)&string_mutable_copy_ptr, 0);
	parson_free(string_mutable_copy);
	return result;
}