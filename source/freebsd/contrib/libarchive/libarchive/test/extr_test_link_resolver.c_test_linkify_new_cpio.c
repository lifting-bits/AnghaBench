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
struct archive_entry_linkresolver {int dummy; } ;
struct archive_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARCHIVE_FORMAT_CPIO_SVR4_NOCRC ; 
 int /*<<< orphan*/  archive_entry_free (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_linkify (struct archive_entry_linkresolver*,struct archive_entry**,struct archive_entry**) ; 
 int /*<<< orphan*/  archive_entry_linkresolver_free (struct archive_entry_linkresolver*) ; 
 struct archive_entry_linkresolver* archive_entry_linkresolver_new () ; 
 int /*<<< orphan*/  archive_entry_linkresolver_set_strategy (struct archive_entry_linkresolver*,int /*<<< orphan*/ ) ; 
 struct archive_entry* archive_entry_new () ; 
 int /*<<< orphan*/  archive_entry_pathname (struct archive_entry*) ; 
 int /*<<< orphan*/  archive_entry_set_dev (struct archive_entry*,int) ; 
 int /*<<< orphan*/  archive_entry_set_ino (struct archive_entry*,int) ; 
 int /*<<< orphan*/  archive_entry_set_nlink (struct archive_entry*,int) ; 
 int /*<<< orphan*/  archive_entry_set_pathname (struct archive_entry*,char*) ; 
 int /*<<< orphan*/  archive_entry_set_size (struct archive_entry*,int) ; 
 int /*<<< orphan*/  archive_entry_size (struct archive_entry*) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  assertEqualInt (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assertEqualString (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void test_linkify_new_cpio(void)
{
	struct archive_entry *entry, *e2;
	struct archive_entry_linkresolver *resolver;

	/* Initialize the resolver. */
	assert(NULL != (resolver = archive_entry_linkresolver_new()));
	archive_entry_linkresolver_set_strategy(resolver,
	    ARCHIVE_FORMAT_CPIO_SVR4_NOCRC);

	/* Create an entry with only 1 link and try to linkify it. */
	assert(NULL != (entry = archive_entry_new()));
	archive_entry_set_pathname(entry, "test1");
	archive_entry_set_ino(entry, 1);
	archive_entry_set_dev(entry, 2);
	archive_entry_set_nlink(entry, 1);
	archive_entry_set_size(entry, 10);
	archive_entry_linkify(resolver, &entry, &e2);

	/* Shouldn't have been changed. */
	assert(e2 == NULL);
	assertEqualInt(10, archive_entry_size(entry));
	assertEqualString("test1", archive_entry_pathname(entry));

	/* Now, try again with an entry that has 3 links. */
	archive_entry_set_pathname(entry, "test2");
	archive_entry_set_nlink(entry, 3);
	archive_entry_set_ino(entry, 2);
	archive_entry_linkify(resolver, &entry, &e2);

	/* First time, it just gets swallowed. */
	assert(entry == NULL);
	assert(e2 == NULL);

	/* Match again. */
	assert(NULL != (entry = archive_entry_new()));
	archive_entry_set_pathname(entry, "test3");
	archive_entry_set_ino(entry, 2);
	archive_entry_set_dev(entry, 2);
	archive_entry_set_nlink(entry, 2);
	archive_entry_set_size(entry, 10);
	archive_entry_linkify(resolver, &entry, &e2);

	/* Should get back "test2" and nothing else. */
	assertEqualString("test2", archive_entry_pathname(entry));
	assertEqualInt(0, archive_entry_size(entry));
	archive_entry_free(entry);
	assert(NULL == e2);
	archive_entry_free(e2); /* This should be a no-op. */

	/* Match a third time. */
	assert(NULL != (entry = archive_entry_new()));
	archive_entry_set_pathname(entry, "test4");
	archive_entry_set_ino(entry, 2);
	archive_entry_set_dev(entry, 2);
	archive_entry_set_nlink(entry, 3);
	archive_entry_set_size(entry, 10);
	archive_entry_linkify(resolver, &entry, &e2);

	/* Should get back "test3". */
	assertEqualString("test3", archive_entry_pathname(entry));
	assertEqualInt(0, archive_entry_size(entry));

	/* Since "test4" was the last link, should get it back also. */
	assertEqualString("test4", archive_entry_pathname(e2));
	assertEqualInt(10, archive_entry_size(e2));

	archive_entry_free(entry);
	archive_entry_free(e2);
	archive_entry_linkresolver_free(resolver);
}