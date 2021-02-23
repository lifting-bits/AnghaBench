#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct super_block {int dummy; } ;
struct TYPE_8__ {int h_err; TYPE_2__* h_transaction; } ;
typedef  TYPE_3__ handle_t ;
struct TYPE_7__ {TYPE_1__* t_journal; } ;
struct TYPE_6__ {struct super_block* j_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ext3_std_error (struct super_block*,char const*,int) ; 
 int journal_stop (TYPE_3__*) ; 

int __ext3_journal_stop(const char *where, handle_t *handle)
{
	struct super_block *sb;
	int err;
	int rc;

	sb = handle->h_transaction->t_journal->j_private;
	err = handle->h_err;
	rc = journal_stop(handle);

	if (!err)
		err = rc;
	if (err)
		__ext3_std_error(sb, where, err);
	return err;
}