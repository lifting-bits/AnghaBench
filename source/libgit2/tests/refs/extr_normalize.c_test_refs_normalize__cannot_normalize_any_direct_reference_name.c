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
 int /*<<< orphan*/  GIT_REFERENCE_FORMAT_NORMAL ; 
 int /*<<< orphan*/  ensure_refname_invalid (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ensure_refname_normalized (int /*<<< orphan*/ ,char*,char*) ; 

void test_refs_normalize__cannot_normalize_any_direct_reference_name(void)
{
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "/a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "//a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "/refs/heads/a/");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a/");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a.");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a.lock");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/foo?bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads\foo");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/v@ation", "refs/heads/v@ation");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs///heads///a", "refs/heads/a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/.a/b");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/foo/../bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/foo..bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/./foo");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/v@{ation");
}