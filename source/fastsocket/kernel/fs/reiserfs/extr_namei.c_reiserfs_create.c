#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct reiserfs_transaction_handle {int dummy; } ;
struct reiserfs_security_handle {int dummy; } ;
struct nameidata {int dummy; } ;
struct inode {int /*<<< orphan*/  i_sb; int /*<<< orphan*/  i_nlink; TYPE_1__* i_mapping; int /*<<< orphan*/ * i_fop; int /*<<< orphan*/ * i_op; } ;
struct TYPE_4__ {int /*<<< orphan*/  len; int /*<<< orphan*/  name; } ;
struct dentry {TYPE_2__ d_name; } ;
struct TYPE_3__ {int /*<<< orphan*/ * a_ops; } ;

/* Variables and functions */
 int ENOMEM ; 
 int JOURNAL_PER_BALANCE_CNT ; 
 int REISERFS_QUOTA_INIT_BLOCKS (int /*<<< orphan*/ ) ; 
 int REISERFS_QUOTA_TRANS_BLOCKS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  d_instantiate (struct dentry*,struct inode*) ; 
 int /*<<< orphan*/  drop_new_inode (struct inode*) ; 
 int /*<<< orphan*/  iput (struct inode*) ; 
 int journal_begin (struct reiserfs_transaction_handle*,int /*<<< orphan*/ ,int) ; 
 int journal_end (struct reiserfs_transaction_handle*,int /*<<< orphan*/ ,int) ; 
 struct inode* new_inode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  new_inode_init (struct inode*,struct inode*,int) ; 
 int reiserfs_add_entry (struct reiserfs_transaction_handle*,struct inode*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct inode*,int) ; 
 int /*<<< orphan*/  reiserfs_address_space_operations ; 
 scalar_t__ reiserfs_cache_default_acl (struct inode*) ; 
 int /*<<< orphan*/  reiserfs_file_inode_operations ; 
 int /*<<< orphan*/  reiserfs_file_operations ; 
 int reiserfs_new_inode (struct reiserfs_transaction_handle*,struct inode*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct dentry*,struct inode*,struct reiserfs_security_handle*) ; 
 int reiserfs_security_init (struct inode*,struct inode*,struct reiserfs_security_handle*) ; 
 int /*<<< orphan*/  reiserfs_update_inode_transaction (struct inode*) ; 
 int /*<<< orphan*/  reiserfs_update_sd (struct reiserfs_transaction_handle*,struct inode*) ; 
 int /*<<< orphan*/  reiserfs_write_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reiserfs_write_unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unlock_new_inode (struct inode*) ; 

__attribute__((used)) static int reiserfs_create(struct inode *dir, struct dentry *dentry, int mode,
			   struct nameidata *nd)
{
	int retval;
	struct inode *inode;
	/* We need blocks for transaction + (user+group)*(quotas for new inode + update of quota for directory owner) */
	int jbegin_count =
	    JOURNAL_PER_BALANCE_CNT * 2 +
	    2 * (REISERFS_QUOTA_INIT_BLOCKS(dir->i_sb) +
		 REISERFS_QUOTA_TRANS_BLOCKS(dir->i_sb));
	struct reiserfs_transaction_handle th;
	struct reiserfs_security_handle security;

	if (!(inode = new_inode(dir->i_sb))) {
		return -ENOMEM;
	}
	new_inode_init(inode, dir, mode);

	jbegin_count += reiserfs_cache_default_acl(dir);
	retval = reiserfs_security_init(dir, inode, &security);
	if (retval < 0) {
		drop_new_inode(inode);
		return retval;
	}
	jbegin_count += retval;
	reiserfs_write_lock(dir->i_sb);

	retval = journal_begin(&th, dir->i_sb, jbegin_count);
	if (retval) {
		drop_new_inode(inode);
		goto out_failed;
	}

	retval =
	    reiserfs_new_inode(&th, dir, mode, NULL, 0 /*i_size */ , dentry,
			       inode, &security);
	if (retval)
		goto out_failed;

	inode->i_op = &reiserfs_file_inode_operations;
	inode->i_fop = &reiserfs_file_operations;
	inode->i_mapping->a_ops = &reiserfs_address_space_operations;

	retval =
	    reiserfs_add_entry(&th, dir, dentry->d_name.name,
			       dentry->d_name.len, inode, 1 /*visible */ );
	if (retval) {
		int err;
		inode->i_nlink--;
		reiserfs_update_sd(&th, inode);
		err = journal_end(&th, dir->i_sb, jbegin_count);
		if (err)
			retval = err;
		unlock_new_inode(inode);
		iput(inode);
		goto out_failed;
	}
	reiserfs_update_inode_transaction(inode);
	reiserfs_update_inode_transaction(dir);

	d_instantiate(dentry, inode);
	unlock_new_inode(inode);
	retval = journal_end(&th, dir->i_sb, jbegin_count);

      out_failed:
	reiserfs_write_unlock(dir->i_sb);
	return retval;
}