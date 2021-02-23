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
typedef  int /*<<< orphan*/  wchar_t ;
struct archive_match {int /*<<< orphan*/  inclusions; } ;
struct archive {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARCHIVE_MATCH_MAGIC ; 
 int /*<<< orphan*/  ARCHIVE_STATE_NEW ; 
 int /*<<< orphan*/  archive_check_magic (struct archive*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int match_list_unmatched_inclusions_next (struct archive_match*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void const**) ; 

int
archive_match_path_unmatched_inclusions_next_w(struct archive *_a,
    const wchar_t **_p)
{
	struct archive_match *a;
	const void *v;
	int r;

	archive_check_magic(_a, ARCHIVE_MATCH_MAGIC,
	    ARCHIVE_STATE_NEW, "archive_match_unmatched_inclusions_next_w");
	a = (struct archive_match *)_a;

	r = match_list_unmatched_inclusions_next(a, &(a->inclusions), 0, &v);
	*_p = (const wchar_t *)v;
	return (r);
}