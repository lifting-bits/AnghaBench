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
 int AE_IFREG ; 
 int /*<<< orphan*/  ARCHIVE_EOF ; 
 int /*<<< orphan*/  ARCHIVE_OK ; 
 int archive_entry_is_encrypted (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_mode (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_pathname (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_size (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_read_close (struct archive*) ; 
 int /*<<< orphan*/  archive_read_free (struct archive*) ; 
 int /*<<< orphan*/  archive_read_has_encrypted_entries (struct archive*) ; 
 struct archive* archive_read_new () ; 
 int /*<<< orphan*/  archive_read_next_header (struct archive*,struct archive_entry**) ; 
 int /*<<< orphan*/  archive_read_support_format_zip (struct archive*) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assertEqualInt (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assertEqualIntA (struct archive*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assertEqualString (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  extract_reference_file (char const*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  read_open_memory_seek (struct archive*,char*,size_t,int) ; 
 char* slurpfile (size_t*,char const*) ; 

__attribute__((used)) static void
verify(const char *refname)
{
	char *p;
	size_t s;
	struct archive *a;
	struct archive_entry *ae;

	extract_reference_file(refname);
	p = slurpfile(&s, refname);

	/* Symlinks can only be extracted with the seeking reader. */
	assert((a = archive_read_new()) != NULL);
	assertEqualIntA(a, ARCHIVE_OK, archive_read_support_format_zip(a));
	assertEqualIntA(a, ARCHIVE_OK, read_open_memory_seek(a, p, s, 1));

	assertEqualIntA(a, ARCHIVE_OK, archive_read_next_header(a, &ae));
	assertEqualString("file0", archive_entry_pathname(ae));
	assertEqualInt(AE_IFREG | 0644, archive_entry_mode(ae));
	assertEqualInt(archive_entry_is_encrypted(ae), 0);
	assertEqualIntA(a, archive_read_has_encrypted_entries(a), 0);

	assertEqualIntA(a, ARCHIVE_OK, archive_read_next_header(a, &ae));
	assertEqualString("build.sh", archive_entry_pathname(ae));
	assertEqualInt(AE_IFREG | 0755, archive_entry_mode(ae));
	assertEqualInt(23, archive_entry_size(ae));
	assertEqualInt(archive_entry_is_encrypted(ae), 0);
	assertEqualIntA(a, archive_read_has_encrypted_entries(a), 0);

	assertEqualIntA(a, ARCHIVE_EOF, archive_read_next_header(a, &ae));
	assertEqualIntA(a, archive_read_has_encrypted_entries(a), 0);
	assertEqualInt(archive_entry_is_encrypted(ae), 0);
	assertEqualIntA(a, ARCHIVE_OK, archive_read_close(a));
	assertEqualIntA(a, ARCHIVE_OK, archive_read_free(a));

	free(p);
}