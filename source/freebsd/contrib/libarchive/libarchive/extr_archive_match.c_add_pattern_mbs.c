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
struct match_list {int dummy; } ;
struct match {int /*<<< orphan*/  pattern; } ;
struct archive_match {int /*<<< orphan*/  setflag; } ;

/* Variables and functions */
 int ARCHIVE_OK ; 
 int /*<<< orphan*/  PATTERN_IS_SET ; 
 int /*<<< orphan*/  archive_mstring_copy_mbs_len (int /*<<< orphan*/ *,char const*,size_t) ; 
 struct match* calloc (int,int) ; 
 int error_nomem (struct archive_match*) ; 
 int /*<<< orphan*/  match_list_add (struct match_list*,struct match*) ; 
 size_t strlen (char const*) ; 

__attribute__((used)) static int
add_pattern_mbs(struct archive_match *a, struct match_list *list,
    const char *pattern)
{
	struct match *match;
	size_t len;

	match = calloc(1, sizeof(*match));
	if (match == NULL)
		return (error_nomem(a));
	/* Both "foo/" and "foo" should match "foo/bar". */
	len = strlen(pattern);
	if (len && pattern[len - 1] == '/')
		--len;
	archive_mstring_copy_mbs_len(&(match->pattern), pattern, len);
	match_list_add(list, match);
	a->setflag |= PATTERN_IS_SET;
	return (ARCHIVE_OK);
}