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
struct archive_match {int dummy; } ;
struct archive {int dummy; } ;

/* Variables and functions */
 int ARCHIVE_OK ; 
 int set_timefilter_pathname_wcs (struct archive_match*,int,int /*<<< orphan*/  const*) ; 
 int validate_time_flag (struct archive*,int,char*) ; 

int
archive_match_include_file_time_w(struct archive *_a, int flag,
    const wchar_t *pathname)
{
	int r;

	r = validate_time_flag(_a, flag, "archive_match_include_file_time_w");
	if (r != ARCHIVE_OK)
		return (r);
	return set_timefilter_pathname_wcs((struct archive_match *)_a,
			flag, pathname);
}