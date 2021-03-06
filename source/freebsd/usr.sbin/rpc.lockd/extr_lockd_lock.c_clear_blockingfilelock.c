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
struct file_lock {int /*<<< orphan*/  client_name; } ;

/* Variables and functions */
 struct file_lock* LIST_FIRST (int /*<<< orphan*/ *) ; 
 struct file_lock* LIST_NEXT (struct file_lock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SM_MAXSTRLEN ; 
 int /*<<< orphan*/  blockedlocklist_head ; 
 int /*<<< orphan*/  deallocate_file_lock (struct file_lock*) ; 
 int /*<<< orphan*/  nfslocklist ; 
 int /*<<< orphan*/  remove_blockingfilelock (struct file_lock*) ; 
 scalar_t__ strncmp (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
clear_blockingfilelock(const char *hostname)
{
	struct file_lock *ifl,*nfl;

	/*
	 * Normally, LIST_FOREACH is called for, but since
	 * the current element *is* the iterator, deleting it
	 * would mess up the iteration.  Thus, a next element
	 * must be used explicitly
	 */

	ifl = LIST_FIRST(&blockedlocklist_head);

	while (ifl != NULL) {
		nfl = LIST_NEXT(ifl, nfslocklist);

		if (strncmp(hostname, ifl->client_name, SM_MAXSTRLEN) == 0) {
			remove_blockingfilelock(ifl);
			deallocate_file_lock(ifl);
		}

		ifl = nfl;
	}
}