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
typedef  size_t int64_t ;
typedef  int /*<<< orphan*/  data ;

/* Variables and functions */
 int ARCHIVE_EOF ; 
 size_t ARCHIVE_FILTER_COMPRESS ; 
 size_t ARCHIVE_FORMAT_TAR_PAX_INTERCHANGE ; 
 int ARCHIVE_OK ; 
 size_t archive_entry_gid (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_gname (struct archive_entry*) ; 
 size_t archive_entry_mode (struct archive_entry*) ; 
 size_t archive_entry_mtime (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_pathname (struct archive_entry*) ; 
 size_t archive_entry_sparse_next (struct archive_entry*,size_t*,size_t*) ; 
 size_t archive_entry_sparse_reset (struct archive_entry*) ; 
 size_t archive_entry_uid (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_uname (struct archive_entry*) ; 
 int archive_filter_code (struct archive*,int /*<<< orphan*/ ) ; 
 int archive_format (struct archive*) ; 
 size_t archive_read_close (struct archive*) ; 
 int archive_read_data_block (struct archive*,void const**,size_t*,size_t*) ; 
 size_t archive_read_free (struct archive*) ; 
 struct archive* archive_read_new () ; 
 int archive_read_next_header (struct archive*,struct archive_entry**) ; 
 int archive_read_open_filename (struct archive*,char*,int) ; 
 int archive_read_support_filter_all (struct archive*) ; 
 int archive_read_support_format_all (struct archive*) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  assertEqualInt (int,size_t) ; 
 int /*<<< orphan*/  assertEqualIntA (struct archive*,int,int) ; 
 int /*<<< orphan*/  assertEqualMem (char const*,char*,int) ; 
 int /*<<< orphan*/  assertEqualString (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  extract_reference_file (char*) ; 
 int /*<<< orphan*/  failure (char*) ; 
 int /*<<< orphan*/  memset (char*,char,int) ; 

__attribute__((used)) static void
test_compat_solaris_pax_sparse_1(void)
{
	char name[] = "test_compat_solaris_pax_sparse_1.pax.Z";
	struct archive_entry *ae;
	struct archive *a;
	int64_t offset, length;
	const void *buff;
	size_t bytes_read;
	char data[1024*8];
	int r;

	assert((a = archive_read_new()) != NULL);
	assertEqualIntA(a, ARCHIVE_OK, archive_read_support_filter_all(a));
	assertEqualIntA(a, ARCHIVE_OK, archive_read_support_format_all(a));
	extract_reference_file(name);
	assertEqualIntA(a, ARCHIVE_OK, archive_read_open_filename(a, name, 10240));

	/* Read first entry. */
	assertEqualIntA(a, ARCHIVE_OK, r = archive_read_next_header(a, &ae));
	if (r != ARCHIVE_OK) {
		archive_read_free(a);
		return;
	}
	assertEqualString("hole", archive_entry_pathname(ae));
	assertEqualInt(1310411683, archive_entry_mtime(ae));
	assertEqualInt(101, archive_entry_uid(ae));
	assertEqualString("cue", archive_entry_uname(ae));
	assertEqualInt(10, archive_entry_gid(ae));
	assertEqualString("staff", archive_entry_gname(ae));
	assertEqualInt(0100644, archive_entry_mode(ae));

	/* Verify the sparse information. */
	failure("This sparse file should have tree data blocks");
	assertEqualInt(3, archive_entry_sparse_reset(ae));
	assertEqualInt(ARCHIVE_OK,
	    archive_entry_sparse_next(ae, &offset, &length));
	assertEqualInt(0, offset);
	assertEqualInt(131072, length);
	assertEqualInt(ARCHIVE_OK,
	    archive_entry_sparse_next(ae, &offset, &length));
	assertEqualInt(393216, offset);
	assertEqualInt(131072, length);
	assertEqualInt(ARCHIVE_OK,
	    archive_entry_sparse_next(ae, &offset, &length));
	assertEqualInt(786432, offset);
	assertEqualInt(32775, length);
	while (ARCHIVE_OK ==
	    archive_read_data_block(a, &buff, &bytes_read, &offset)) {
		failure("The data blocks should not include the hole");
		assert((offset >= 0 && offset + bytes_read <= 131072) ||
		       (offset >= 393216 && offset + bytes_read <= 393216+131072) ||
		       (offset >= 786432 && offset + bytes_read <= 786432+32775));
		if (offset == 0 && bytes_read >= 1024*8) {
			memset(data, 'a', sizeof(data));
			failure("First data block should be 8K bytes of 'a'");
			assertEqualMem(buff, data, sizeof(data));
		} else if (offset + bytes_read == 819207 && bytes_read >= 7) {
			const char *last = buff;
			last += bytes_read - 7;
			memset(data, 'c', 7);
			failure("Last seven bytes should be all 'c'");
			assertEqualMem(last, data, 7);
		}
	}

	/* Verify the end-of-archive. */
	assertEqualIntA(a, ARCHIVE_EOF, archive_read_next_header(a, &ae));

	/* Verify that the format detection worked. */
	assertEqualInt(archive_filter_code(a, 0), ARCHIVE_FILTER_COMPRESS);
	assertEqualInt(archive_format(a), ARCHIVE_FORMAT_TAR_PAX_INTERCHANGE);

	assertEqualInt(ARCHIVE_OK, archive_read_close(a));
	assertEqualInt(ARCHIVE_OK, archive_read_free(a));
}