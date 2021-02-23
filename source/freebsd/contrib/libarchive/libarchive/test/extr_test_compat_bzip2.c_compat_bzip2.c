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
struct archive_entry {int dummy; } ;
struct archive {int dummy; } ;

/* Variables and functions */
 scalar_t__ ARCHIVE_EOF ; 
 int /*<<< orphan*/  ARCHIVE_FILTER_BZIP2 ; 
 int /*<<< orphan*/  ARCHIVE_FORMAT_TAR_USTAR ; 
 scalar_t__ ARCHIVE_OK ; 
 char* archive_entry_pathname (struct archive_entry*) ; 
 scalar_t__ archive_filter_code (struct archive*,int /*<<< orphan*/ ) ; 
 char const* archive_filter_name (struct archive*,int /*<<< orphan*/ ) ; 
 scalar_t__ archive_format (struct archive*) ; 
 int /*<<< orphan*/  archive_read_close (struct archive*) ; 
 int /*<<< orphan*/  archive_read_free (struct archive*) ; 
 struct archive* archive_read_new () ; 
 int /*<<< orphan*/  archive_read_next_header (struct archive*,struct archive_entry**) ; 
 int /*<<< orphan*/  archive_read_open_filename (struct archive*,char const*,int) ; 
 scalar_t__ archive_read_support_filter_bzip2 (struct archive*) ; 
 int /*<<< orphan*/  archive_read_support_format_all (struct archive*) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assertEqualInt (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assertEqualIntA (struct archive*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assertEqualString (char const*,char*) ; 
 int /*<<< orphan*/  extract_reference_file (char const*) ; 
 int /*<<< orphan*/  failure (char*,int,char const*,char const*) ; 
 int /*<<< orphan*/  skipping (char*) ; 

__attribute__((used)) static void
compat_bzip2(const char *name)
{
	const char *n[7] = { "f1", "f2", "f3", "d1/f1", "d1/f2", "d1/f3", NULL };
	struct archive_entry *ae;
	struct archive *a;
	int i;

	assert((a = archive_read_new()) != NULL);
	if (ARCHIVE_OK != archive_read_support_filter_bzip2(a)) {
		skipping("Unsupported bzip2");
		return;
	}
	assertEqualIntA(a, ARCHIVE_OK, archive_read_support_format_all(a));
	extract_reference_file(name);
	assertEqualIntA(a, ARCHIVE_OK, archive_read_open_filename(a, name, 2));

	/* Read entries, match up names with list above. */
	for (i = 0; i < 6; ++i) {
		failure("Could not read file %d (%s) from %s", i, n[i], name);
		assertEqualIntA(a, ARCHIVE_OK,
		    archive_read_next_header(a, &ae));
		assertEqualString(n[i], archive_entry_pathname(ae));
	}

	/* Verify the end-of-archive. */
	assertEqualIntA(a, ARCHIVE_EOF, archive_read_next_header(a, &ae));

	/* Verify that the format detection worked. */
	assertEqualInt(archive_filter_code(a, 0), ARCHIVE_FILTER_BZIP2);
	assertEqualString(archive_filter_name(a, 0), "bzip2");
	assertEqualInt(archive_format(a), ARCHIVE_FORMAT_TAR_USTAR);

	assertEqualIntA(a, ARCHIVE_OK, archive_read_close(a));
	assertEqualInt(archive_filter_code(a, 0), ARCHIVE_FILTER_BZIP2);
	assertEqualString(archive_filter_name(a, 0), "bzip2");
	assertEqualInt(archive_format(a), ARCHIVE_FORMAT_TAR_USTAR);

	assertEqualInt(ARCHIVE_OK, archive_read_free(a));
}